// =============================================================================
// inverse_kinematics.cpp  -  see inverse_kinematics.hpp
// =============================================================================
#include "inverse_kinematics.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace stewart {

IKLayout ikLayout(int N) {
    // MATLAB (1-based):  in = 1:3,  b{k} = 3 + 3(k-1) + (1:3),
    //                    s{k} = 3 + 3N + 6(k-1) + (1:6),  free = 3 + 3N + 6(N-1) + (1:3)
    // Below: the same, 0-based.
    IKLayout lay;
    lay.in = {0, 1, 2};
    lay.b.resize(N);
    for (int k = 0; k < N; ++k) lay.b[k] = {3 + 3 * k, 4 + 3 * k, 5 + 3 * k};
    lay.s.resize(std::max(N - 1, 0));
    for (int k = 0; k < N - 1; ++k)
        for (int i = 0; i < 6; ++i) lay.s[k][i] = 3 + 3 * N + 6 * k + i;
    for (int i = 0; i < 3; ++i) lay.free[i] = 3 + 3 * N + 6 * (N - 1) + i;
    lay.bFirst = 3;
    lay.bLast = 3 + 3 * N;
    lay.nAng = 3 + 3 * N;
    lay.n = 9 * N;
    return lay;
}

void ikEqsN(const VecX& x, const System& sys, const Vec6& target, const PoseMask& spec,
            const IKLayout& lay, VecX& F, MatX& J) {
    const int N = sys.N();

    // ---- pose of every top plate --------------------------------------------
    // top[0..N-2]: read from x.  top[N-1]: prescribed values from target,
    // the 3 free ones from x.
    std::vector<Vec6> s(N);
    for (int k = 0; k < N - 1; ++k)
        for (int i = 0; i < 6; ++i) s[k][i] = x[lay.s[k][i]];
    s[N - 1] = target;
    for (int i = 0, f = 0; i < 6; ++i)
        if (!spec[i]) s[N - 1][i] = x[lay.free[f++]];

    // ---- rotation (+ derivatives) and hinge centroid of every top plate ------
    std::vector<RotationAndDerivatives> R(N);
    std::vector<Vec3> cp(N);
    for (int k = 0; k < N; ++k) {
        R[k] = rotZYX(s[k].tail<3>());
        cp[k] = sys.top[k].O.rowwise().mean();
    }

    F.setZero(lay.n);
    J.setZero(lay.n, lay.n);

    for (int k = 0; k < N; ++k) {
        const Stage& bk = sys.bot[k];
        const Stage& tk = sys.top[k];
        for (int j = 0; j < 3; ++j) {
            const int r = 9 * k + 3 * j;   // first of the 3 rows of this joint

            // ---- bottom side: where the bottom link ends, in the world --------
            Vec3 pBot;
            if (k == 0) {
                // base: world frame, input angle is an unknown
                const double ph = x[lay.in[j]];
                pBot = bk.O.col(j) + bk.m[j] * wvec(bk.beta[j], ph);
                J.block<3, 1>(r, lay.in[j]) = bk.m[j] * dwvec(bk.beta[j], ph);
            } else {
                // on top[k-1]: input angle comes from the coupling
                const double ph = sys.cpl * x[lay.b[k - 1][j]] + sys.off;
                const Vec3 qb = bk.O.col(j) + bk.m[j] * wvec(bk.beta[j], ph) - cp[k - 1];
                pBot = R[k - 1].Q * qb + s[k - 1].head<3>();
                // d/d(phi_b of the stage below)  (chain rule through the coupling)
                J.block<3, 1>(r, lay.b[k - 1][j]) =
                    sys.cpl * R[k - 1].Q * (bk.m[j] * dwvec(bk.beta[j], ph));
                // d/d(position of top[k-1]) = identity
                for (int i = 0; i < 3; ++i) J(r + i, lay.s[k - 1][i]) = 1.0;
                // d/d(roll, pitch, yaw of top[k-1])
                for (int i = 0; i < 3; ++i)
                    J.block<3, 1>(r, lay.s[k - 1][3 + i]) = R[k - 1].dQ[i] * qb;
            }

            // ---- top side: where the top link ends, in the world --------------
            const double ph = x[lay.b[k][j]];
            const Vec3 qt = tk.O.col(j) + tk.m[j] * wvec(tk.beta[j], ph) - cp[k];
            F.segment<3>(r) = pBot - (R[k].Q * qt + s[k].head<3>());
            J.block<3, 1>(r, lay.b[k][j]) = -R[k].Q * (tk.m[j] * dwvec(tk.beta[j], ph));

            // derivative w.r.t. the pose of top[k] (minus sign: it is subtracted)
            Eigen::Matrix<double, 3, 6> dS;
            dS.leftCols<3>() = -Mat3::Identity();
            for (int i = 0; i < 3; ++i) dS.col(3 + i) = -R[k].dQ[i] * qt;

            if (k < N - 1) {
                for (int i = 0; i < 6; ++i) J.block<3, 1>(r, lay.s[k][i]) = dS.col(i);
            } else {
                // last plate: only its free components are unknowns
                for (int i = 0, f = 0; i < 6; ++i)
                    if (!spec[i]) J.block<3, 1>(r, lay.free[f++]) = dS.col(i);
            }
        }
    }
}

IKResult solveIKN(const System& sys, const Vec6& target, const PoseMask& spec,
                  const VecX& x0, const IKLayout& lay) {
    VecX x = x0;
    VecX F;
    MatX J;
    for (int it = 0; it < 60; ++it) {
        ikEqsN(x, sys, target, spec, lay, F, J);
        Eigen::PartialPivLU<MatX> lu(J);
        if (!(lu.rcond() >= 1e-13)) break;   // singular (or NaN): give up
        VecX dx = -lu.solve(F);              // Newton step: J dx = -F
        const double len = dx.norm();
        if (len > 0.5) dx *= 0.5 / len;      // limit the step size
        x += dx;
        if (dx.norm() < 1e-13) break;        // converged
    }

    // Final verdict on the end point.
    ikEqsN(x, sys, target, spec, lay, F, J);
    IKResult res;
    res.x = x;
    res.rc = Eigen::PartialPivLU<MatX>(J).rcond();
    res.ok = x.allFinite() && F.norm() < 1e-10 && res.rc > 1e-13;
    return res;
}

IKResult trackIKN(const System& sys, const Vec6& tPrev, const Vec6& tNew, const PoseMask& spec,
                  const VecX& xPrev, const IKLayout& lay) {
    // Largest allowed change per sub-step of each prescribed component.
    Vec6 scale;
    scale << 0.05, 0.05, 0.05, 2.0 * DEG, 2.0 * DEG, 2.0 * DEG;

    Vec6 d = tNew - tPrev;
    for (int i = 0; i < 6; ++i)
        if (!spec[i]) d[i] = 0.0;   // only prescribed components move
    const int n0 = std::max(1, static_cast<int>(std::ceil((d.cwiseAbs().cwiseQuotient(scale)).maxCoeff())));

    IKResult res;
    res.x = xPrev;
    res.rc = std::numeric_limits<double>::quiet_NaN();
    for (int doubling = 0; doubling <= 5; ++doubling) {
        const int nSub = n0 << doubling;   // n0, 2 n0, 4 n0, ..., 32 n0
        VecX x = xPrev;
        bool ok = true;
        double rc = std::numeric_limits<double>::quiet_NaN();
        for (int q = 1; q <= nSub; ++q) {
            const Vec6 tq = tPrev + d * (static_cast<double>(q) / nSub);
            const IKResult r = solveIKN(sys, tq, spec, x, lay);
            rc = r.rc;
            // reject failures and sudden jumps of any joint angle (> 10 deg)
            const double jump =
                angWrapVec(r.x.head(lay.nAng) - x.head(lay.nAng)).cwiseAbs().maxCoeff();
            if (!r.ok || !(jump <= 10.0 * DEG)) {
                ok = false;
                break;
            }
            x = r.x;
        }
        res.x = x;
        res.ok = ok;
        res.rc = rc;
        if (ok) return res;
    }
    return res;   // every refinement failed: res.ok == false
}

VecX seedFromChain(const std::vector<StageSolution>& S, const Vec3& phiIn,
                   const PoseMask& spec, const IKLayout& lay) {
    const int N = static_cast<int>(S.size());
    VecX x = VecX::Zero(lay.n);
    for (int j = 0; j < 3; ++j) x[lay.in[j]] = phiIn[j];
    for (int k = 0; k < N; ++k)
        for (int j = 0; j < 3; ++j) x[lay.b[k][j]] = S[k].phi[j];
    for (int k = 0; k < N - 1; ++k) {
        const Vec6 sk = poseVector(S[k].Q, S[k].Ow.rowwise().mean());
        for (int i = 0; i < 6; ++i) x[lay.s[k][i]] = sk[i];
    }
    const Vec6 sN = poseVector(S[N - 1].Q, S[N - 1].Ow.rowwise().mean());
    for (int i = 0, f = 0; i < 6; ++i)
        if (!spec[i]) x[lay.free[f++]] = sN[i];
    return x;
}

VecX seedFromFrame(const Vec3& phiIn, const std::vector<Vec3>& phiTop,
                   const std::vector<Vec6>& pose, const PoseMask& spec, const IKLayout& lay) {
    const int N = static_cast<int>(phiTop.size());
    VecX x = VecX::Zero(lay.n);
    for (int j = 0; j < 3; ++j) x[lay.in[j]] = phiIn[j];
    for (int k = 0; k < N; ++k)
        for (int j = 0; j < 3; ++j) x[lay.b[k][j]] = phiTop[k][j];
    for (int k = 0; k < N - 1; ++k)
        for (int i = 0; i < 6; ++i) x[lay.s[k][i]] = pose[k][i];
    for (int i = 0, f = 0; i < 6; ++i)
        if (!spec[i]) x[lay.free[f++]] = pose[N - 1][i];
    return x;
}

}  // namespace stewart
