// =============================================================================
// simulation.cpp  -  see simulation.hpp for the step-by-step overview
// =============================================================================
#include "simulation.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stdexcept>

namespace stewart {
namespace {   // helpers used only in this file

constexpr double kSubStep = 2.0 * DEG;    // largest input change per FK sub-step
constexpr double kMaxReadingStep = PI;    // larger changes between two readings are rejected
constexpr double kRoundTripTol = 1e-6;    // IK -> FK check of the prescribed pose values

Stage buildPlate(const PlateInput& p) {
    return stageFromPoints(p.R, p.S, p.T, p.m, p.deltaDeg * DEG);
}

Vec6 poseOf(const StageSolution& s) {
    return poseVector(s.Q, s.Ow.rowwise().mean());
}

}  // namespace

Geometry defaultGeometry() {
    Geometry geo;
    geo.nStages = 2;

    // BASE = bottom of stage 1, in WORLD coordinates.
    const double r3 = 80.0 * std::sqrt(3.0);   // 80*sqrt(3) = 138.56
    geo.base.R = Vec2(0.0, 160.0);
    geo.base.S = Vec2(-r3, -80.0);
    geo.base.T = Vec2(r3, -80.0);
    geo.base.m = Vec3(120.0, 120.0, 120.0);          // link lengths
    geo.base.deltaDeg = Vec3(0.0, 0.0, 0.0);   // 0 = links swing toward the centroid

    // Top plates in their OWN frames. An empty entry means "same as the base".
    // Example of a different top plate for stage 2:
    //   PlateInput t = geo.base;  t.m = Vec3(2.5, 2.5, 2.5);  geo.tops = {std::nullopt, t};
    geo.tops = {};

    // Link lengths of the bottom of stage k >= 2 (hinged on top[k-1]).
    // Empty -> same as top[k-1].m. Index 0 is unused (that is the base).
    geo.botM = {};

    // 'Straight': top link + next bottom link form one straight bar
    // 'Mirror'  : next bottom link at the mirrored angle
    geo.coupling = Coupling::Straight;

    geo.topAssembly = 1;
    return geo;
}

Simulation::Simulation(const Geometry& geo, double maxJump)
    : topAssembly_(std::max(geo.topAssembly, 1)), maxJump_(maxJump) {
    if (!(maxJump > 0.0)) throw std::invalid_argument("maxJump must be > 0");

    const int N = std::max(1, geo.nStages);
    sys_.bot.resize(N);
    sys_.top.resize(N);

    sys_.bot[0] = buildPlate(geo.base);
    for (int k = 0; k < N; ++k) {
        // top plate: user value, or the base design
        const bool hasTop = k < static_cast<int>(geo.tops.size()) && geo.tops[k].has_value();
        sys_.top[k] = buildPlate(hasTop ? *geo.tops[k] : geo.base);

        // bottom of stages 2, 3, ...: the hinges of top[k-1] (same corners and
        // beta, which the 'straight' coupling needs), only m may differ.
        if (k >= 1) {
            sys_.bot[k] = sys_.top[k - 1];
            if (k < static_cast<int>(geo.botM.size()) && geo.botM[k].has_value()) {
                if ((geo.botM[k]->array() <= 0.0).any())
                    throw std::invalid_argument("botM: link lengths must be > 0");
                sys_.bot[k].m = *geo.botM[k];
            }
        }
    }

    if (geo.coupling == Coupling::Straight) {
        sys_.cpl = 1.0;   // phi_in(k+1) = phi_b(k) + 180 deg
        sys_.off = PI;
    } else {
        sys_.cpl = -1.0;  // phi_in(k+1) = -phi_b(k)
        sys_.off = 0.0;
    }
}

FKUpdate Simulation::update(const Config& cfg) {
    const Vec3& phiIn = cfg.motorPos;
    if (!phiIn.allFinite()) return hold("motor position is not finite", 0.0);
    if (!init_) return initialize(phiIn);

    const double maxStep = (phiIn - inPrev_).cwiseAbs().maxCoeff();
    if (maxStep > kMaxReadingStep) {
        char msg[128];
        std::snprintf(msg, sizeof msg, "motor reading changed by %.1f deg since the last accepted one",
                      rad2deg(maxStep));
        return hold(msg, 0.0);
    }

    // Sub-steps of at most 2 deg, so fkChain can follow the right branch.
    const int nSub = std::max(1, static_cast<int>(std::ceil(maxStep / kSubStep)));
    std::vector<Vec3> pP(sys_.N());
    for (int k = 0; k < sys_.N(); ++k) pP[k] = S_[k].phi;
    ChainResult chain;
    double jmp = 0.0;
    for (int q = 1; q <= nSub; ++q) {
        const Vec3 inQ = inPrev_ + (phiIn - inPrev_) * (static_cast<double>(q) / nSub);
        chain = fkChain(sys_, inQ, pP);
        if (!chain.ok) return hold("a stage cannot be assembled (no real solution)", jmp);
        jmp = std::max(jmp, chain.jmp);
        if (chain.jmp > maxJump_) {
            char msg[128];
            std::snprintf(msg, sizeof msg, "the solution would jump %.1f deg to another configuration",
                          rad2deg(chain.jmp));
            return hold(msg, jmp);
        }
        for (int k = 0; k < sys_.N(); ++k) pP[k] = chain.S[k].phi;
    }
    return accept(phiIn, chain.S, jmp);
}

FKUpdate Simulation::initialize(const Vec3& phiIn) {
    // Solve stage by stage and pick the requested configuration of every top
    // plate (highest first, stable like MATLAB's sort).
    std::vector<StageSolution> S(sys_.N());
    Mat3 Qb = Mat3::Identity();
    Vec3 pb = Vec3::Zero();
    Vec3 ph = phiIn;
    for (int k = 0; k < sys_.N(); ++k) {
        std::vector<StageSolution> sols = solveStage(sys_.bot[k], Qb, pb, ph, sys_.top[k]);
        if (sols.empty())
            return hold("stage " + std::to_string(k + 1) + " cannot be assembled at the first reading", 0.0);
        std::stable_sort(sols.begin(), sols.end(),
                         [](const StageSolution& a, const StageSolution& b) { return a.zc > b.zc; });
        const int iSel = std::min(topAssembly_, static_cast<int>(sols.size())) - 1;
        S[k] = sols[iSel];

        // the next stage sits on this top plate
        Qb = S[k].Q;
        pb = S[k].p;
        ph = (sys_.cpl * S[k].phi).array() + sys_.off;
    }
    return accept(phiIn, S, 0.0);
}

FKUpdate Simulation::accept(const Vec3& phiIn, const std::vector<StageSolution>& S, double jmp) {
    init_ = true;
    inPrev_ = phiIn;
    S_ = S;
    last_.valid = true;
    last_.held = false;
    last_.reason.clear();
    last_.jmp = jmp;
    last_.pose = poseOf(S.back());
    last_.Q = S.back().Q;
    return last_;
}

FKUpdate Simulation::hold(const std::string& reason, double jmp) const {
    FKUpdate out = last_;   // previous pose (valid = false before the first good reading)
    out.held = true;
    out.reason = reason;
    out.jmp = jmp;
    return out;
}

IKUpdate Simulation::inverse(const Vec6& target, const PoseMask& spec) const {
    IKUpdate out;
    if (!init_) {
        out.reason = "no motor reading has been accepted yet";
        return out;
    }
    if (std::count(spec.begin(), spec.end(), true) != 3) {
        out.reason = "ikSpec must select exactly 3 of x, y, z, roll, pitch, yaw";
        return out;
    }
    if (!target.allFinite()) {
        out.reason = "target is not finite";
        return out;
    }

    // Start from the current solution, so the IK stays on the current branch.
    const IKLayout lay = ikLayout(sys_.N());
    const VecX x0 = seedFromChain(S_, inPrev_, spec, lay);
    const Vec6 tPrev = last_.pose;
    Vec6 tNew = target;
    for (int i = 3; i < 6; ++i)   // take the short way around for the angles
        tNew[i] = tPrev[i] + angWrap(target[i] - tPrev[i]);

    const IKResult r = trackIKN(sys_, tPrev, tNew, spec, x0, lay);
    out.rc = r.rc;
    if (!r.ok) {
        out.reason = "IK did not converge: the target is outside the workspace or at a singularity";
        return out;
    }
    for (int j = 0; j < 3; ++j) out.motorPos[j] = r.x[lay.in[j]];
    out.pose = tNew;
    for (int i = 0, f = 0; i < 6; ++i)
        if (!spec[i]) out.pose[i] = r.x[lay.free[f++]];
    for (int i = 3; i < 6; ++i) out.pose[i] = angWrap(out.pose[i]);

    // Round trip: driving the motors there must make the forward kinematics
    // (with its branch tracking) land on the target, not on another branch.
    Simulation probe = *this;
    const FKUpdate fk = probe.update(Config{out.motorPos});
    double e = 0.0;
    for (int i = 0; i < 6; ++i) {
        if (!spec[i]) continue;
        const double d = fk.pose[i] - out.pose[i];
        e = std::max(e, std::abs(i < 3 ? d : angWrap(d)));
    }
    if (!fk.valid || fk.held || !(e <= kRoundTripTol)) {
        out.reason = "the forward kinematics would not reach the target on the current branch" +
                     (fk.held ? " (" + fk.reason + ")" : std::string());
        return out;
    }
    out.ok = true;
    return out;
}

}  // namespace stewart
