// =============================================================================
// forward_chain.hpp  -  forward kinematics of the whole stack
// -----------------------------------------------------------------------------
// Given the three input angles of the base, find where every plate is.
//
// Stage k (k = 0 .. N-1) has a bottom plate bot[k] and a top plate top[k]:
//   * bot[0] is the fixed base (its frame IS the world frame)
//   * bot[k] for k >= 1 sits on top[k-1] and is expressed in top[k-1]'s frame
//
// Per stage (solveStage):
//   1. joints from the bottom plate's angles (jointPositions), into the world
//   2. measure the joint triangle: b = (|RS|, |ST|, |TR|)
//   3. stewartDK on the TOP plate -> every way the top can sit on those joints
//   4. fitRigid -> pose (Q, p) of the top plate for each of those ways
// Then fkChain picks one solution per stage and couples it to the next stage:
//   phi_in(k+1) = cpl * phi_b(k) + off
//     'straight' coupling: cpl =  1, off = pi  (one straight bar through the hinge)
//     'mirror'   coupling: cpl = -1, off = 0   (mirror image across the plate)
// =============================================================================
#pragma once

#include <vector>

#include "direct_kinematics.hpp"
#include "stage.hpp"

namespace stewart {

enum class Coupling { Straight, Mirror };

// Everything that describes the mechanism (no motion data).
struct System {
    std::vector<Stage> bot;   // bot[0] = base, bot[k] on top[k-1]
    std::vector<Stage> top;   // top plate of each stage, in its own frame
    double cpl = 1.0;         // coupling factor  (see header comment)
    double off = PI;          // coupling offset  [rad]

    int N() const { return static_cast<int>(top.size()); }
};

// One solved stage (one assembly configuration of its top plate).
struct StageSolution {
    Vec3 phi;    // phi_b: link angles of the TOP plate, in the top plate's frame [rad]
    Mat3 Pw;     // columns: joints R, S, T in the world
    Mat3 Ow;     // columns: top hinge corners in the world
    Mat3 Q;      // pose of the top plate:  world = Q * local + p
    Vec3 p;
    double zc;   // mean height of Ow (used to rank configurations at home)
    Vec3 b;      // joint triangle sides |RS|, |ST|, |TR|
    Mat3 Qb;     // pose of the BOTTOM plate that was used
    Vec3 pb;
};

// -----------------------------------------------------------------------------
// solveStage: every configuration of one stage.
//   bot, top : the stage's plates
//   Qb, pb   : pose of the bottom plate in the world (identity/zero for the base)
//   phiIn    : link angles of the bottom plate [rad]
// -----------------------------------------------------------------------------
std::vector<StageSolution> solveStage(const Stage& bot, const Mat3& Qb, const Vec3& pb,
                                      const Vec3& phiIn, const Stage& top);

// -----------------------------------------------------------------------------
// fkChain: all stages, bottom to top. In each stage it keeps the configuration
// whose angles are nearest to phiPrev[k] (the previous frame), so the motion
// stays on one continuous branch.
//   ok  = false if some stage has no real solution (cannot be assembled)
//   jmp = largest distance (2-norm of the wrapped angle change) that had to be
//         accepted; a big value means it jumped to another configuration.
// -----------------------------------------------------------------------------
struct ChainResult {
    std::vector<StageSolution> S;   // one per stage
    bool ok = false;
    double jmp = 0.0;
};
ChainResult fkChain(const System& sys, const Vec3& phiIn, const std::vector<Vec3>& phiPrev);

// -----------------------------------------------------------------------------
// linkCheckStage: verification only (replaces MATLAB's legCheckStage).
// Returns the largest violation of
//   * every link keeping its length m (bottom and top side), and
//   * every link staying in its swing plane (perpendicular to its hinge axis).
// Should be ~1e-14 for a correct solution.
// -----------------------------------------------------------------------------
double linkCheckStage(const Stage& bot, const Stage& top, const StageSolution& s);

}  // namespace stewart
