// =============================================================================
// simulation.cpp  -  see simulation.hpp for the step-by-step overview
// =============================================================================
#include "simulation.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits>
#include <stdexcept>

namespace stewart {
namespace {   // helpers used only in this file

const double NaN = std::numeric_limits<double>::quiet_NaN();
const char* const kPoseNames[6] = {"x", "y", "z", "roll", "pitch", "yaw"};
const char kJointNames[3] = {'R', 'S', 'T'};

// Everything we keep for one animation frame.
struct Frame {
    bool valid = false;
    Vec3 phiIn = Vec3::Constant(NaN);   // input angles of the base [rad]
    std::vector<StageSolution> S;       // one solved stage per stage
    std::vector<Vec6> pose;             // pose of every top plate
    std::vector<Vec3> phiTop;           // phi_b of every top plate [rad]
    double errL = NaN;                  // largest link check violation
};

Stage buildPlate(const PlateInput& p) {
    return stageFromPoints(p.R, p.S, p.T, p.m, p.deltaDeg * DEG);
}

// (x, y, z, roll, pitch, yaw) with angles in degrees -> angles in radians
Vec6 toSI(const Vec6& v) {
    Vec6 out = v;
    out.tail<3>() *= DEG;
    return out;
}

Vec3 rad2degVec(const Vec3& v) { return v / DEG; }

std::string specNames(const PoseMask& spec) {
    std::string s;
    for (int i = 0; i < 6; ++i)
        if (spec[i]) s += (s.empty() ? "" : ", ") + std::string(kPoseNames[i]);
    return s;
}

// ---------------------------------------------------------------------------
// One CSV row per frame (angles in degrees). Invalid frames are written with
// valid = 0 and "nan" everywhere else, so frame numbers stay aligned.
// ---------------------------------------------------------------------------
void writeCsv(const std::string& path, const std::vector<Frame>& frames, const System& sys) {
    std::FILE* fp = std::fopen(path.c_str(), "w");
    if (!fp) throw std::runtime_error("cannot open " + path + " for writing");
    const int N = sys.N();

    // ---- header
    std::fprintf(fp, "frame,valid,errL,in_R,in_S,in_T");
    for (int k = 1; k <= N; ++k) {
        for (char j : kJointNames) std::fprintf(fp, ",s%d_phib_%c", k, j);
        for (const char* nm : kPoseNames) std::fprintf(fp, ",s%d_%s", k, nm);
        for (const char* grp : {"P", "O", "B"})   // joints, top corners, bottom corners
            for (char j : kJointNames)
                for (char c : {'x', 'y', 'z'}) std::fprintf(fp, ",s%d_%s%c_%c", k, grp, j, c);
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c) std::fprintf(fp, ",s%d_Q%d%d", k, r, c);
    }
    std::fprintf(fp, "\n");

    // ---- rows
    const int nCols = 3 + N * (3 + 6 + 27 + 9);   // values after frame,valid
    for (std::size_t f = 0; f < frames.size(); ++f) {
        const Frame& fr = frames[f];
        std::fprintf(fp, "%zu,%d", f + 1, fr.valid ? 1 : 0);
        if (!fr.valid) {
            for (int i = 0; i < nCols + 1; ++i) std::fprintf(fp, ",nan");
            std::fprintf(fp, "\n");
            continue;
        }
        std::fprintf(fp, ",%.6e", fr.errL);
        for (int j = 0; j < 3; ++j) std::fprintf(fp, ",%.15g", rad2deg(fr.phiIn[j]));
        for (int k = 0; k < N; ++k) {
            const StageSolution& s = fr.S[k];
            for (int j = 0; j < 3; ++j) std::fprintf(fp, ",%.15g", rad2deg(s.phi[j]));
            for (int i = 0; i < 6; ++i)
                std::fprintf(fp, ",%.15g", i < 3 ? fr.pose[k][i] : rad2deg(fr.pose[k][i]));
            const Mat3 Bw = (s.Qb * sys.bot[k].O).colwise() + s.pb;   // bottom corners, world
            for (const Mat3* M : {&s.Pw, &s.Ow, &Bw})
                for (int j = 0; j < 3; ++j)
                    for (int c = 0; c < 3; ++c) std::fprintf(fp, ",%.15g", (*M)(c, j));
            for (int r = 0; r < 3; ++r)
                for (int c = 0; c < 3; ++c) std::fprintf(fp, ",%.15g", s.Q(r, c));
        }
        std::fprintf(fp, "\n");
    }
    std::fclose(fp);
}

}  // namespace

int run(const Config& cfg) {
    // =========================================================================
    // 1. SETUP
    // =========================================================================
    const int N = std::max(1, cfg.nStages);
    System sys;
    sys.bot.resize(N);
    sys.top.resize(N);

    sys.bot[0] = buildPlate(cfg.base);
    for (int k = 0; k < N; ++k) {
        // top plate: user value, or the base design
        const bool hasTop = k < static_cast<int>(cfg.tops.size()) && cfg.tops[k].has_value();
        sys.top[k] = buildPlate(hasTop ? *cfg.tops[k] : cfg.base);

        // bottom of stages 2, 3, ...: the hinges of top[k-1] (same corners and
        // beta, which the 'straight' coupling needs), only m may differ.
        if (k >= 1) {
            sys.bot[k] = sys.top[k - 1];
            if (k < static_cast<int>(cfg.botM.size()) && cfg.botM[k].has_value()) {
                if ((cfg.botM[k]->array() <= 0.0).any())
                    throw std::invalid_argument("botM: link lengths must be > 0");
                sys.bot[k].m = *cfg.botM[k];
            }
        }
    }

    if (cfg.coupling == Coupling::Straight) {
        sys.cpl = 1.0;   // phi_in(k+1) = phi_b(k) + 180 deg
        sys.off = PI;
    } else {
        sys.cpl = -1.0;  // phi_in(k+1) = -phi_b(k)
        sys.off = 0.0;
    }

    // All stages identical (and mirror coupling)? Then top_k = (pose of top_1)^k,
    // which is checked further down.
    bool sameAll = (cfg.coupling == Coupling::Mirror);
    for (int k = 0; k < N; ++k) {
        sameAll = sameAll && sameStage(sys.top[k], sys.bot[0]);
        if (k >= 1) sameAll = sameAll && sameStage(sys.bot[k], sys.bot[0]);
    }

    // Start input angles: given, or chosen so the joints of stage 1 sit at h0.
    Vec3 phi0;
    if (cfg.phi0Deg) {
        phi0 = *cfg.phi0Deg * DEG;
    } else {
        const double mMin = sys.bot[0].m.minCoeff();
        if (cfg.h0 >= mMin) {
            char msg[128];
            std::snprintf(msg, sizeof msg, "h0 must be smaller than the shortest link m = %.3f", mMin);
            throw std::invalid_argument(msg);
        }
        for (int j = 0; j < 3; ++j) phi0[j] = std::asin(cfg.h0 / sys.bot[0].m[j]);
    }
    std::printf("%d stage(s), inputs phi_rs, phi_ss, phi_ts = %.3f %.3f %.3f deg\n", N,
                rad2deg(phi0[0]), rad2deg(phi0[1]), rad2deg(phi0[2]));

    // =========================================================================
    // 2. HOME CONFIGURATION, stage by stage
    // =========================================================================
    std::vector<StageSolution> home(N);
    {
        Mat3 Qb = Mat3::Identity();
        Vec3 pb = Vec3::Zero();
        Vec3 ph = phi0;
        for (int k = 0; k < N; ++k) {
            std::vector<StageSolution> sols = solveStage(sys.bot[k], Qb, pb, ph, sys.top[k]);
            if (sols.empty()) {
                throw std::runtime_error("Stage " + std::to_string(k + 1) +
                                         " cannot be assembled at the start pose - change phi0/h0 or the geometry");
            }
            // highest top plate first (stable, like MATLAB's sort)
            std::stable_sort(sols.begin(), sols.end(),
                             [](const StageSolution& a, const StageSolution& b) { return a.zc > b.zc; });

            std::printf("Stage %d: |RS| = %.4f |ST| = %.4f |TR| = %.4f, %zu real configuration(s)\n",
                        k + 1, sols[0].b[0], sols[0].b[1], sols[0].b[2], sols.size());
            for (std::size_t i = 0; i < sols.size(); ++i) {
                const Vec3 a = rad2degVec(sols[i].phi);
                std::printf("   #%zu  phi_b = %8.3f %8.3f %8.3f deg   (top%d centroid z = %.3f)\n",
                            i + 1, a[0], a[1], a[2], k + 1, sols[i].zc);
            }
            const int iSel = std::min(std::max(cfg.topAssembly, 1), static_cast<int>(sols.size())) - 1;
            std::printf("   using #%d\n", iSel + 1);
            home[k] = sols[iSel];

            // the next stage sits on this top plate
            Qb = home[k].Q;
            pb = home[k].p;
            ph = (sys.cpl * home[k].phi).array() + sys.off;

            if (k < N - 1) {
                // coupling in the sketch's convention: angles from the plate, inward
                const Vec3 aTop = -rad2degVec(home[k].phi);
                const Vec3 aBot = rad2degVec(angWrapVec(ph));
                std::printf("   coupling at top%d: top%d link angles [%.5g %.5g %.5g] deg"
                            " -> bottom%d inputs [%.5g %.5g %.5g] deg\n",
                            k + 1, k + 1, aTop[0], aTop[1], aTop[2], k + 2, aBot[0], aBot[1], aBot[2]);
            }
        }
    }

    // =========================================================================
    // 3. IK LAYOUT, start vector and start pose of the last plate
    // =========================================================================
    const PoseMask& spec = cfg.ikSpec;
    if (std::count(spec.begin(), spec.end(), true) != 3)
        throw std::invalid_argument("ikSpec must select exactly 3 of x, y, z, roll, pitch, yaw");
    const IKLayout lay = ikLayout(N);
    const VecX xHome = seedFromChain(home, phi0, spec, lay);
    const Vec6 sHome = poseVector(home[N - 1].Q, home[N - 1].Ow.rowwise().mean());
    std::printf("Start pose of top%d: x = %.3f  y = %.3f  z = %.3f   roll = %.2f  pitch = %.2f  yaw = %.2f deg\n",
                N, sHome[0], sHome[1], sHome[2], rad2deg(sHome[3]), rad2deg(sHome[4]), rad2deg(sHome[5]));

    // =========================================================================
    // 4. INPUT ANGLES PER FRAME: prescribed, or from the inverse kinematics
    // =========================================================================
    const int nFrames = std::max(1, cfg.nFrames);
    auto tau = [nFrames](int f) {   // MATLAB: linspace(0, 2*pi, nFrames)
        return nFrames > 1 ? 2.0 * PI * f / (nFrames - 1) : 0.0;
    };

    std::vector<Vec3> phiIn(nFrames, Vec3::Constant(NaN));
    std::vector<Vec6> TGT;              // pose targets (pose mode)
    std::vector<VecX> XIK;              // IK solutions (pose mode)
    std::vector<bool> ikOk;

    if (cfg.drive == DriveMode::Inputs) {
        for (int f = 0; f < nFrames; ++f) {
            for (int j = 0; j < 3; ++j)
                phiIn[f][j] = phi0[j] + cfg.phiAmpDeg[j] * DEG * std::sin(tau(f) + cfg.phiPhaseDeg[j] * DEG);
        }
    } else {
        const Vec6 pose0v = cfg.pose0 ? toSI(*cfg.pose0) : sHome;
        const Vec6 amp = toSI(cfg.poseAmp);
        TGT.resize(nFrames);
        XIK.assign(nFrames, VecX::Constant(lay.n, NaN));
        ikOk.assign(nFrames, false);
        double minRc = std::numeric_limits<double>::infinity();
        int nSolved = 0;

        VecX xPrev = xHome;
        Vec6 tPrev = sHome;
        for (int f = 0; f < nFrames; ++f) {
            for (int i = 0; i < 6; ++i)
                TGT[f][i] = pose0v[i] + amp[i] * std::sin(tau(f) + cfg.posePhaseDeg[i] * DEG);
            const IKResult r = trackIKN(sys, tPrev, TGT[f], spec, xPrev, lay);
            if (!r.ok) {
                std::fprintf(stderr, "warning: Frame %d: IK did not converge - the target is outside the "
                                     "workspace or at a singularity (frame skipped). Reduce poseAmp.\n", f + 1);
                continue;
            }
            XIK[f] = r.x;
            ikOk[f] = true;
            minRc = std::min(minRc, r.rc);
            ++nSolved;
            xPrev = r.x;
            tPrev = TGT[f];
            for (int j = 0; j < 3; ++j) phiIn[f][j] = r.x[lay.in[j]];
        }
        std::printf("IK (%dx%d Newton): prescribed %s of top%d, solved %d/%d frames, smallest rcond(J) = %.2e\n",
                    lay.n, lay.n, specNames(spec).c_str(), N, nSolved, nFrames, minRc);
    }

    // =========================================================================
    // 5. FORWARD KINEMATICS OF EVERY FRAME (continuity per stage)
    // =========================================================================
    std::vector<Frame> frames(nFrames);
    std::vector<Vec3> phiPrev(N);
    for (int k = 0; k < N; ++k) phiPrev[k] = home[k].phi;
    Vec3 inPrev = phi0;

    for (int f = 0; f < nFrames; ++f) {
        if (!phiIn[f].allFinite()) continue;   // IK failed for this frame

        // Sub-steps of at most 2 deg, so fkChain can follow the right branch.
        const double maxStep = (phiIn[f] - inPrev).cwiseAbs().maxCoeff();
        const int nSub = std::max(1, static_cast<int>(std::ceil(maxStep / (2.0 * DEG))));
        bool ok = true;
        std::vector<Vec3> pP = phiPrev;
        ChainResult chain;
        for (int q = 1; q <= nSub; ++q) {
            const Vec3 inQ = inPrev + (phiIn[f] - inPrev) * (static_cast<double>(q) / nSub);
            chain = fkChain(sys, inQ, pP);
            if (!chain.ok) {
                ok = false;
                break;
            }
            if (chain.jmp > 15.0 * DEG)
                std::fprintf(stderr, "warning: Frame %d: jumped %.1f deg to another configuration.\n",
                             f + 1, rad2deg(chain.jmp));
            for (int k = 0; k < N; ++k) pP[k] = chain.S[k].phi;
        }
        if (!ok) {
            std::fprintf(stderr, "warning: Frame %d: a stage cannot be assembled (no real solution) - frame skipped.\n",
                         f + 1);
            continue;
        }
        phiPrev = pP;
        inPrev = phiIn[f];

        Frame& fr = frames[f];
        fr.valid = true;
        fr.phiIn = phiIn[f];
        fr.S = chain.S;
        fr.errL = 0.0;
        for (int k = 0; k < N; ++k) {
            const StageSolution& s = chain.S[k];
            fr.pose.push_back(poseVector(s.Q, s.Ow.rowwise().mean()));
            fr.phiTop.push_back(s.phi);
            fr.errL = std::max(fr.errL, linkCheckStage(sys.bot[k], sys.top[k], s));
        }
    }

    std::vector<int> good;
    double maxErrL = 0.0;
    for (int f = 0; f < nFrames; ++f) {
        if (frames[f].valid) {
            good.push_back(f);
            maxErrL = std::max(maxErrL, frames[f].errL);
        }
    }
    if (good.empty()) throw std::runtime_error("No frame could be solved.");
    std::printf("Frames solved: %zu/%d\n", good.size(), nFrames);
    std::printf("Check - all %d links keep their length and swing plane: max error = %.2e\n", 6 * N, maxErrL);

    // =========================================================================
    // 6. CHECKS
    // =========================================================================
    // ---- identical stages (mirror coupling): top_k = (pose of top_1)^k
    if (sameAll && N >= 2) {
        double eS = 0.0;
        for (int f : good) {
            const Mat3& Q1 = frames[f].S[0].Q;
            const Vec3& p1 = frames[f].S[0].p;
            Mat3 Qk = Q1;
            Vec3 pk = p1;
            for (int k = 1; k < N; ++k) {
                Qk = Q1 * Qk;        // compose the stage-1 motion once more
                pk = Q1 * pk + p1;
                eS = std::max({eS, (Qk - frames[f].S[k].Q).norm(), (pk - frames[f].S[k].p).norm()});
            }
        }
        std::printf("Check - identical stages: top_k = (pose of top1)^k, max error = %.2e\n", eS);
    }

    // ---- round trip FK <-> IK
    if (cfg.drive == DriveMode::Pose) {
        // FK of the IK's input angles must land on the prescribed pose, and
        // agree with the IK's free pose values and top angles.
        double eT = 0.0, eF = 0.0, eB = 0.0;
        for (int f : good) {
            const Vec6& pN = frames[f].pose[N - 1];
            for (int i = 0, fi = 0; i < 6; ++i) {
                if (spec[i]) eT = std::max(eT, std::abs(pN[i] - TGT[f][i]));
                else eF = std::max(eF, std::abs(pN[i] - XIK[f][lay.free[fi++]]));
            }
            for (int k = 0; k < N; ++k)
                for (int j = 0; j < 3; ++j)
                    eB = std::max(eB, std::abs(angWrap(frames[f].phiTop[k][j] - XIK[f][lay.b[k][j]])));
        }
        std::printf("Round trip IK -> FK: prescribed pose of top%d error = %.2e, free pose error = %.2e, "
                    "top angles = %.2e deg\n", N, eT, eF, rad2deg(eB));
    } else {
        // IK of the FK's poses must give back the input angles.
        VecX xPrev = xHome;
        Vec6 tPrev = sHome;
        double eIkMax = 0.0, minRc = std::numeric_limits<double>::infinity();
        int nOk = 0, nOther = 0;
        for (int f : good) {
            const Frame& fr = frames[f];
            const IKResult r = trackIKN(sys, tPrev, fr.pose[N - 1], spec, xPrev, lay);
            if (r.ok) {
                double e = 0.0;
                for (int j = 0; j < 3; ++j) e = std::max(e, std::abs(angWrap(r.x[lay.in[j]] - fr.phiIn[j])));
                eIkMax = std::max(eIkMax, e);
                minRc = std::min(minRc, r.rc);
                if (e > 1e-6 * DEG) ++nOther;
                ++nOk;
            }
            // next start guess: this frame's FK values (always on the right branch)
            xPrev = seedFromFrame(fr.phiIn, fr.phiTop, fr.pose, spec, lay);
            tPrev = fr.pose[N - 1];
        }
        std::printf("Round trip FK -> IK (prescribed %s of top%d): %d/%zu frames, input error = %.2e deg\n"
                    "  smallest rcond of the %dx%d IK Jacobian along the path = %.2e\n",
                    specNames(spec).c_str(), N, nOk, good.size(), rad2deg(eIkMax), lay.n, lay.n, minRc);
        if (nOther > 0) {
            std::printf("  %d frame(s) gave ANOTHER valid IK solution (same prescribed pose): the\n"
                        "  path passes close to an IK singularity, where two solutions meet.\n", nOther);
        }
    }

    // =========================================================================
    // 7. OUTPUT
    // =========================================================================
    writeCsv(cfg.csvPath, frames, sys);
    std::printf("Wrote %s (%d frames). Animate it with:  python3 plot_frames.py %s\n",
                cfg.csvPath.c_str(), nFrames, cfg.csvPath.c_str());
    return 0;
}

}  // namespace stewart
