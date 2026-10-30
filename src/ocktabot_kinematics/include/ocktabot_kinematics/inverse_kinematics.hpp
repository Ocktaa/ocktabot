// =============================================================================
// inverse_kinematics.hpp  -  inverse kinematics of the whole stack
// -----------------------------------------------------------------------------
// Given 3 of the 6 pose values of the LAST plate (e.g. its x, y, z), find the
// base input angles (and everything else).
//
// Unknown vector x (length 9N), in this order:
//   [ phi_in of the base (3) | phi_b of every top plate (3N) |
//     full pose of top[0] .. top[N-2] (6 each) | the 3 FREE pose values of top[N-1] ]
// Equations (9N): at every joint of every stage the bottom link and the top
// link must end at the same point (3 coordinates x 3 joints x N stages):
//   Q_{k-1} (O_bot + m w(phi_in) - c_{k-1}) + s_{k-1}.xyz
//      = Q_k (O_top + m w(phi_b) - c_k) + s_k.xyz
// with phi_in(k) = cpl * phi_b(k-1) + off for k >= 1, and c_k = centroid of
// top[k]'s hinge corners in its own frame.
// Solved with Newton's method (analytic Jacobian), continued from the previous
// frame so the solution stays on the same branch.
// =============================================================================
#pragma once

#include <array>
#include <vector>

#include "forward_chain.hpp"

namespace stewart {

// Which pose components of the last plate are PRESCRIBED (exactly 3 true).
// Order: x, y, z, roll, pitch, yaw.
using PoseMask = std::array<bool, 6>;

// -----------------------------------------------------------------------------
// IKLayout: where each group of unknowns lives inside x (0-based indices).
// -----------------------------------------------------------------------------
struct IKLayout {
    std::array<int, 3> in{};                // phi_in of the base
    std::vector<std::array<int, 3>> b;      // b[k]: phi_b of top[k]
    std::vector<std::array<int, 6>> s;      // s[k]: pose of top[k], k = 0..N-2
    std::array<int, 3> free{};              // free pose values of top[N-1]
    int bFirst = 0, bLast = 0;              // all phi_b live in x[bFirst .. bLast)
    int nAng = 0;                           // x[0 .. nAng) are all joint angles
    int n = 0;                              // total length = 9N
};
IKLayout ikLayout(int N);

// -----------------------------------------------------------------------------
// ikEqsN: the 9N residuals F(x) and the 9N x 9N Jacobian J = dF/dx.
// F = 0 means every joint closes. target = desired pose of the last plate
// (only the components where spec is true are used).
// -----------------------------------------------------------------------------
void ikEqsN(const VecX& x, const System& sys, const Vec6& target, const PoseMask& spec,
            const IKLayout& lay, VecX& F, MatX& J);

// Result of an IK solve.
struct IKResult {
    VecX x;            // solution (or the last good guess if !ok)
    bool ok = false;   // converged and well-conditioned
    double rc = 0.0;   // reciprocal condition number of J (small = near a singularity)
};

// -----------------------------------------------------------------------------
// solveIKN: Newton's method from the start guess x0 (at most 60 steps, each
// step limited to length 0.5).
// -----------------------------------------------------------------------------
IKResult solveIKN(const System& sys, const Vec6& target, const PoseMask& spec,
                  const VecX& x0, const IKLayout& lay);

// -----------------------------------------------------------------------------
// trackIKN: move from the solved pose tPrev (solution xPrev) to the new pose
// tNew in small steps (<= 0.05 length units / 2 deg per step). If Newton fails
// or any joint angle jumps more than 10 deg in one step, it retries with twice
// as many steps (up to 32x).
// -----------------------------------------------------------------------------
IKResult trackIKN(const System& sys, const Vec6& tPrev, const Vec6& tNew, const PoseMask& spec,
                  const VecX& xPrev, const IKLayout& lay);

// -----------------------------------------------------------------------------
// Start guesses for the IK, built from forward-kinematics results.
//   seedFromChain : from a solved chain (one StageSolution per stage)
//   seedFromFrame : from stored per-frame values (angles and poses)
// -----------------------------------------------------------------------------
VecX seedFromChain(const std::vector<StageSolution>& S, const Vec3& phiIn,
                   const PoseMask& spec, const IKLayout& lay);
VecX seedFromFrame(const Vec3& phiIn, const std::vector<Vec3>& phiTop,
                   const std::vector<Vec6>& pose, const PoseMask& spec, const IKLayout& lay);

}  // namespace stewart
