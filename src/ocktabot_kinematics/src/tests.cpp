// =============================================================================
// tests.cpp  -  bottom-up checks, in the order you would implement the code
// -----------------------------------------------------------------------------
// Run:  ./build/stewart_tests
// Each line prints PASS/FAIL with the measured error. If a lower layer fails,
// fix it first: everything above it depends on it.
// =============================================================================
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <string>

#include "inverse_kinematics.hpp"

using namespace stewart;

static int gFailures = 0;

static void check(const std::string& name, double err, double tol) {
    const bool ok = err <= tol;   // NaN fails too
    if (!ok) ++gFailures;
    std::printf("[%s] %-52s err = %.2e  (tol %.0e)\n", ok ? "PASS" : "FAIL", name.c_str(), err, tol);
}

// The default plate: equilateral hinge triangle at radius 4, links of length 3.
static Stage defaultPlate() {
    const double r3 = 2.0 * std::sqrt(3.0);
    return stageFromPoints(Vec2(0, 4), Vec2(-r3, -2), Vec2(r3, -2), Vec3(3, 3, 3), Vec3::Zero());
}

int main() {
    // ---------------------------------------------------------------- layer 1
    std::printf("\n-- layer 1: utilities --\n");
    check("angWrap(190 deg) = -170 deg", std::abs(angWrap(190 * DEG) - (-170 * DEG)), 1e-14);
    check("angWrap(-200 deg) = 160 deg", std::abs(angWrap(-200 * DEG) - (160 * DEG)), 1e-14);
    check("angWrap(90 deg) unchanged", std::abs(angWrap(90 * DEG) - 90 * DEG), 1e-14);

    check("rotZYX(0,0,0) = identity", (rotZYX(Vec3::Zero()).Q - Mat3::Identity()).norm(), 1e-15);

    const Vec3 ang(0.3, -0.4, 1.1);   // roll, pitch, yaw [rad]
    check("poseVector(rotZYX(a)) gives a back",
          (poseVector(rotZYX(ang).Q, Vec3::Zero()).tail<3>() - ang).norm(), 1e-14);

    {   // derivatives of rotZYX against central finite differences
        const double h = 1e-6;
        double e = 0;
        const RotationAndDerivatives R = rotZYX(ang);
        for (int i = 0; i < 3; ++i) {
            Vec3 a1 = ang, a2 = ang;
            a1[i] += h;
            a2[i] -= h;
            const Mat3 fd = (rotZYX(a1).Q - rotZYX(a2).Q) / (2 * h);
            e = std::max(e, (fd - R.dQ[i]).norm());
        }
        check("rotZYX derivatives match finite differences", e, 1e-8);
    }
    {   // dwvec against finite differences
        const double h = 1e-6, beta = 0.7, phi = 0.4;
        const Vec3 fd = (wvec(beta, phi + h) - wvec(beta, phi - h)) / (2 * h);
        check("dwvec matches finite differences", (fd - dwvec(beta, phi)).norm(), 1e-9);
    }
    {   // fitRigid recovers a known rigid motion
        const Mat3 Q = rotZYX(ang).Q;
        const Vec3 p(1, -2, 3);
        const Mat3 A = defaultPlate().O;
        const Mat3 B = (Q * A).colwise() + p;
        const RigidTransform t = fitRigid(A, B);
        check("fitRigid recovers Q and p", (t.Q - Q).norm() + (t.p - p).norm(), 1e-12);
    }
    {   // realRoots: (x - 1)(x + 2)(x - 3) = x^3 - 2x^2 - 5x + 6, ASCENDING powers
        std::vector<double> r = realRoots({6, -5, -2, 1});
        std::sort(r.begin(), r.end());
        const double e = r.size() == 3 ? std::abs(r[0] + 2) + std::abs(r[1] - 1) + std::abs(r[2] - 3) : 1e9;
        check("realRoots of (x-1)(x+2)(x-3)", e, 1e-12);
        check("realRoots of x^2 + 1 has no real roots", static_cast<double>(realRoots({1, 0, 1}).size()), 0);
    }

    // ---------------------------------------------------------------- layer 2
    std::printf("\n-- layer 2: plate geometry --\n");
    const Stage plate = defaultPlate();
    {
        // links point at the centroid: R at (0, 4) swings toward -y, i.e. beta = -90 deg
        const Vec3 expected(-90 * DEG, 30 * DEG, 150 * DEG);
        check("default beta = (-90, 30, 150) deg", angWrapVec(plate.beta - expected).norm(), 1e-14);
        bool threw = false;
        try {
            stageFromPoints(Vec2(0, 0), Vec2(1, 1), Vec2(2, 2), Vec3(3, 3, 3), Vec3::Zero());
        } catch (const std::invalid_argument&) {
            threw = true;
        }
        check("collinear R, S, T are rejected", threw ? 0.0 : 1.0, 0);
    }

    // ---------------------------------------------------------------- layer 3
    std::printf("\n-- layer 3: the paper's direct kinematics --\n");
    {
        // Joints at phi = 53.13 deg (height 2.4) form a triangle; stewartDK must
        // find configurations that reproduce exactly those sides.
        const Vec3 phi = Vec3::Constant(std::asin(2.4 / 3.0));
        const Mat3 P = jointPositions(plate, phi);
        const Vec3 b((P.col(0) - P.col(1)).norm(), (P.col(1) - P.col(2)).norm(), (P.col(2) - P.col(0)).norm());
        const std::vector<DKSolution> sols = stewartDK(plate, b);
        double e = 0;
        bool foundStart = false;
        for (const DKSolution& s : sols) {
            const Mat3& Q = s.P;
            e = std::max({e, std::abs((Q.col(0) - Q.col(1)).norm() - b[0]),
                             std::abs((Q.col(1) - Q.col(2)).norm() - b[1]),
                             std::abs((Q.col(2) - Q.col(0)).norm() - b[2])});
            if (angWrapVec(s.phi - phi).norm() < 1e-9) foundStart = true;
        }
        check("stewartDK finds 8 configurations", std::abs(static_cast<double>(sols.size()) - 8), 0);
        check("every configuration reproduces the sides b", e, 1e-12);
        check("the configuration we started from is among them", foundStart ? 0.0 : 1.0, 0);
    }

    // ---------------------------------------------------------------- layer 4
    std::printf("\n-- layer 4: forward kinematics of the stack --\n");
    System sys;
    sys.bot = {plate, plate};
    sys.top = {plate, plate};
    sys.cpl = 1.0;   // straight coupling
    sys.off = PI;
    const Vec3 phi0 = Vec3::Constant(std::asin(2.4 / 3.0));
    std::vector<StageSolution> home;
    {
        Mat3 Qb = Mat3::Identity();
        Vec3 pb = Vec3::Zero();
        Vec3 ph = phi0;
        for (int k = 0; k < 2; ++k) {
            std::vector<StageSolution> s = solveStage(sys.bot[k], Qb, pb, ph, sys.top[k]);
            std::stable_sort(s.begin(), s.end(),
                             [](const StageSolution& a, const StageSolution& b) { return a.zc > b.zc; });
            home.push_back(s.at(0));
            Qb = s[0].Q;
            pb = s[0].p;
            ph = (sys.cpl * s[0].phi).array() + sys.off;
        }
        check("top1 centroid at z = 2 * h0 = 4.8", std::abs(home[0].zc - 4.8), 1e-12);
        check("top2 centroid at z = 4 * h0 = 9.6", std::abs(home[1].zc - 9.6), 1e-12);
        check("top1 is level (Q = identity)", (home[0].Q - Mat3::Identity()).norm(), 1e-12);
        check("links keep length and swing plane",
              std::max(linkCheckStage(sys.bot[0], sys.top[0], home[0]),
                       linkCheckStage(sys.bot[1], sys.top[1], home[1])), 1e-12);

        // fkChain with phiPrev = home must reproduce home
        const ChainResult c = fkChain(sys, phi0, {home[0].phi, home[1].phi});
        check("fkChain from home stays at home", c.ok ? (c.S[1].p - home[1].p).norm() : 1e9, 1e-12);
    }

    // ---------------------------------------------------------------- layer 5
    std::printf("\n-- layer 5: inverse kinematics --\n");
    {
        const PoseMask spec{true, true, true, false, false, false};
        const IKLayout lay = ikLayout(2);
        const VecX x0 = seedFromChain(home, phi0, spec, lay);
        const Vec6 sHome = poseVector(home[1].Q, home[1].Ow.rowwise().mean());

        // At the home pose the loop-closure equations must already be satisfied.
        VecX F;
        MatX J;
        ikEqsN(x0, sys, sHome, spec, lay, F, J);
        check("ikEqsN residual is zero at the home pose", F.norm(), 1e-12);

        // Analytic Jacobian against finite differences (this is where index bugs hide).
        const double h = 1e-6;
        double e = 0;
        for (int i = 0; i < lay.n; ++i) {
            VecX xp = x0, xm = x0, Fp, Fm;
            MatX unused;
            xp[i] += h;
            xm[i] -= h;
            ikEqsN(xp, sys, sHome, spec, lay, Fp, unused);
            ikEqsN(xm, sys, sHome, spec, lay, Fm, unused);
            e = std::max(e, ((Fp - Fm) / (2 * h) - J.col(i)).cwiseAbs().maxCoeff());
        }
        check("ikEqsN Jacobian matches finite differences", e, 1e-7);

        // Move the last plate 0.3 sideways; FK of the IK's inputs must land there.
        Vec6 target = sHome;
        target[0] += 0.3;
        const IKResult r = trackIKN(sys, sHome, target, spec, x0, lay);
        check("trackIKN converges", r.ok ? 0.0 : 1.0, 0);
        const Vec3 phiIn(r.x[0], r.x[1], r.x[2]);
        const ChainResult c = fkChain(sys, phiIn, {Vec3(r.x[3], r.x[4], r.x[5]), Vec3(r.x[6], r.x[7], r.x[8])});
        const Vec3 reached = c.ok ? Vec3(c.S[1].Ow.rowwise().mean()) : Vec3::Constant(1e9);
        check("FK of the IK inputs reaches the target", (reached - target.head<3>()).norm(), 1e-9);
    }

    std::printf("\n%s: %d failure(s)\n", gFailures == 0 ? "ALL PASSED" : "SOME FAILED", gFailures);
    return gFailures == 0 ? 0 : 1;
}
