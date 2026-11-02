// =============================================================================
// simulation.hpp  -  the script part of stewart_stacked.m, driven by the motors
// -----------------------------------------------------------------------------
// Geometry describes the mechanism (fixed for the lifetime of the robot).
// Config is the ONLY per-update input: the current position of the 3 motors.
//
// Simulation keeps the last accepted solution, so every update stays on the
// same assembly branch:
//   1. first update   solve every stage, pick the requested configuration
//                     (topAssembly: 1 = highest top plate, 2 = next ...)
//   2. every update   forward kinematics from the last accepted motor angles to
//                     the new ones in <= 2 deg sub-steps (branch tracking)
//   3. hold           if a stage cannot be assembled, or the solution would jump
//                     to another configuration, the new reading is rejected and
//                     the previous end-effector pose is kept
//   4. inverse        IK of a target pose of the last plate, continued from the
//                     current (held) solution so it stays on the same branch
// =============================================================================
#pragma once

#include <optional>
#include <string>
#include <vector>

#include "inverse_kinematics.hpp"

namespace stewart {

// One plate, as the user describes it.
struct PlateInput {
    Vec2 R, S, T;      // hinge corners (x, y) in the plate's own frame
    Vec3 m;            // link lengths
    Vec3 deltaDeg;     // beta offset from "toward the centroid" [deg]
};

// Everything that describes the mechanism (no motion data).
struct Geometry {
    int nStages = 2;

    PlateInput base;                              // bottom plate of stage 1 (world frame)
    std::vector<std::optional<PlateInput>> tops;  // tops[k]; missing/empty -> same as base
    std::vector<std::optional<Vec3>> botM;        // botM[k] (k >= 1): link lengths of the
                                                  // bottom of stage k on top[k-1];
                                                  // missing/empty -> top[k-1].m
    Coupling coupling = Coupling::Straight;

    // configuration of every top plate at the first motor reading:
    // 1 = highest, 2 = next ...
    int topAssembly = 1;
};

// The defaults of the MATLAB script: an equilateral hinge triangle at radius 4,
// links of length 3 swinging toward the centroid, two stacked stages.
Geometry defaultGeometry();

// The input of one simulation step: the current position of the motors.
struct Config {
    Vec3 motorPos = Vec3::Zero();   // input angles phi_in of the base links R, S, T [rad]
};

// Result of one forward-kinematics update.
struct FKUpdate {
    bool valid = false;   // a pose is available (false only before the first good reading)
    bool held = false;    // the new reading was rejected, pose = previous pose
    std::string reason;   // why it was held (empty if not)
    double jmp = 0.0;     // largest per-stage angle change of one sub-step [rad]
    Vec6 pose = Vec6::Zero();       // (x, y, z, roll, pitch, yaw) of the last top plate,
                                    // (x, y, z) = centroid of its hinge corners
    Mat3 Q = Mat3::Identity();      // its rotation (same as roll, pitch, yaw)
};

// Result of an inverse-kinematics request.
struct IKUpdate {
    bool ok = false;
    std::string reason;             // why it failed (empty if ok)
    Vec3 motorPos = Vec3::Zero();   // input angles phi_in of the base links [rad]
    Vec6 pose = Vec6::Zero();       // full pose of the last plate at that solution
    double rc = 0.0;                // reciprocal condition number of the IK Jacobian
};

class Simulation {
public:
    // maxJump: largest accepted change of the top angles of one stage per
    //          sub-step (2-norm, [rad]); bigger means another configuration.
    // Throws std::invalid_argument for an invalid geometry.
    explicit Simulation(const Geometry& geo, double maxJump = 15.0 * DEG);

    // Forward kinematics for a new motor reading. Returns the pose to publish.
    FKUpdate update(const Config& cfg);

    // Motor angles that put the last plate at `target` (x, y, z, roll, pitch,
    // yaw; angles in rad). The mechanism has 3 inputs, so only the 3 components
    // where spec is true are enforced; the others follow from the mechanism and
    // are returned in IKUpdate::pose. Does not change the simulation state.
    IKUpdate inverse(const Vec6& target, const PoseMask& spec) const;

    bool hasState() const { return init_; }
    const System& system() const { return sys_; }

private:
    FKUpdate initialize(const Vec3& phiIn);
    FKUpdate accept(const Vec3& phiIn, const std::vector<StageSolution>& S, double jmp);
    FKUpdate hold(const std::string& reason, double jmp) const;

    System sys_;
    int topAssembly_ = 1;
    double maxJump_;

    // last accepted solution
    bool init_ = false;
    Vec3 inPrev_ = Vec3::Zero();
    std::vector<StageSolution> S_;
    FKUpdate last_;
};

}  // namespace stewart
