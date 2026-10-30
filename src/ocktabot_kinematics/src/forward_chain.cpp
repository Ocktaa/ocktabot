// =============================================================================
// forward_chain.cpp  -  see forward_chain.hpp
// =============================================================================
#include "forward_chain.hpp"

#include <algorithm>
#include <limits>

namespace stewart {

std::vector<StageSolution> solveStage(const Stage& bot, const Mat3& Qb, const Vec3& pb,
                                      const Vec3& phiIn, const Stage& top) {
    // ---- 1. joints in the bottom plate's frame (eq. 2), then into the world
    const Mat3 Pw = (Qb * jointPositions(bot, phiIn)).colwise() + pb;

    // ---- 2. sides of the joint triangle
    const Vec3 b((Pw.col(0) - Pw.col(1)).norm(),
                 (Pw.col(1) - Pw.col(2)).norm(),
                 (Pw.col(2) - Pw.col(0)).norm());

    // ---- 3. the paper's direct kinematics, with the TOP plate playing the
    //         role of the "base": it finds the angles phi_b of the top plate's
    //         links (in the top plate's own frame) that reach a triangle with
    //         these sides.
    const std::vector<DKSolution> dk = stewartDK(top, b);

    // ---- 4. for each configuration: where is the top plate in the world?
    //         dk.P are the joints in the TOP frame, Pw the same joints in the
    //         WORLD -> the rigid transform between them is the top plate's pose.
    std::vector<StageSolution> out;
    out.reserve(dk.size());
    for (const DKSolution& d : dk) {
        const RigidTransform t = fitRigid(d.P, Pw);
        StageSolution s;
        s.phi = d.phi;
        s.Pw = Pw;
        s.Ow = (t.Q * top.O).colwise() + t.p;
        s.Q = t.Q;
        s.p = t.p;
        s.zc = s.Ow.row(2).mean();
        s.b = b;
        s.Qb = Qb;
        s.pb = pb;
        out.push_back(s);
    }
    return out;
}

ChainResult fkChain(const System& sys, const Vec3& phiIn, const std::vector<Vec3>& phiPrev) {
    ChainResult res;
    res.S.reserve(sys.N());

    Mat3 Qb = Mat3::Identity();   // stage 0 sits on the base = world frame
    Vec3 pb = Vec3::Zero();
    Vec3 ph = phiIn;              // input angles of the current bottom plate

    for (int k = 0; k < sys.N(); ++k) {
        const std::vector<StageSolution> sols = solveStage(sys.bot[k], Qb, pb, ph, sys.top[k]);
        if (sols.empty()) {
            res.ok = false;   // this stage cannot be assembled
            return res;
        }

        // Branch tracking: nearest configuration to the previous frame.
        std::size_t best = 0;
        double bestDist = std::numeric_limits<double>::infinity();
        for (std::size_t i = 0; i < sols.size(); ++i) {
            const double d = angWrapVec(sols[i].phi - phiPrev[k]).norm();
            if (d < bestDist) {
                bestDist = d;
                best = i;
            }
        }
        res.jmp = std::max(res.jmp, bestDist);
        res.S.push_back(sols[best]);

        // Coupling: the top of this stage is the bottom of the next one.
        Qb = sols[best].Q;
        pb = sols[best].p;
        ph = (sys.cpl * sols[best].phi).array() + sys.off;
    }
    res.ok = true;
    return res;
}

double linkCheckStage(const Stage& bot, const Stage& top, const StageSolution& s) {
    double e = 0.0;
    for (int j = 0; j < 3; ++j) {
        const Vec3 P  = s.Pw.col(j);
        const Vec3 Ob = s.Qb * bot.O.col(j) + s.pb;   // bottom hinge corner, world
        const Vec3 Ot = s.Q  * top.O.col(j) + s.p;    // top hinge corner, world
        const Vec3 ub = s.Qb * bot.u.col(j);          // hinge axes, world
        const Vec3 ut = s.Q  * top.u.col(j);
        // link lengths
        e = std::max(e, std::abs((P - Ob).norm() - bot.m[j]));
        e = std::max(e, std::abs((P - Ot).norm() - top.m[j]));
        // each link perpendicular to its hinge axis (stays in its swing plane)
        e = std::max(e, std::abs((P - Ob).dot(ub)));
        e = std::max(e, std::abs((P - Ot).dot(ut)));
    }
    return e;
}

}  // namespace stewart
