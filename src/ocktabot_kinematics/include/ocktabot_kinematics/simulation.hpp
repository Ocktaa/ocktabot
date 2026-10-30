// =============================================================================
// simulation.hpp  -  the script part of stewart_stacked.m
// -----------------------------------------------------------------------------
// Config holds every user input (the "USER INPUTS" block of the MATLAB file),
// with angles in DEGREES like the MATLAB inputs. run() does the rest:
//   1. setup        build every plate with stageFromPoints, coupling constants
//   2. home pose    solve every stage at phi0, pick the requested configuration
//   3. drive        input angles per frame: sinusoid ('inputs') or from the IK
//                   tracking a pose of the last plate ('pose')
//   4. per frame    forward kinematics with <= 2 deg sub-steps (branch tracking)
//   5. checks       link lengths, identical-stage property, FK <-> IK round trip
//   6. output       one CSV row per frame (plot it with plot_frames.py)
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

enum class DriveMode { Inputs, Pose };

struct Config {
    int nStages = 2;

    // ---- geometry
    PlateInput base;                              // bottom plate of stage 1 (world frame)
    std::vector<std::optional<PlateInput>> tops;  // tops[k]; missing/empty -> same as base
    std::vector<std::optional<Vec3>> botM;        // botM[k] (k >= 1): link lengths of the
                                                  // bottom of stage k on top[k-1];
                                                  // missing/empty -> top[k-1].m
    Coupling coupling = Coupling::Straight;

    // ---- what drives the motion
    DriveMode drive = DriveMode::Inputs;

    // ---- driveMode Inputs:  phi(t) = phi0 + phiAmp * sin(tau + phiPhase)   [deg]
    std::optional<Vec3> phi0Deg;   // empty -> joints of stage 1 level at height h0
    double h0 = 2.4;
    Vec3 phiAmpDeg{10, 10, 10};
    Vec3 phiPhaseDeg{0, 120, 240};
    int nFrames = 180;             // tau goes from 0 to 2 pi over the frames

    // ---- driveMode Pose:  s(t) = pose0 + poseAmp * sin(tau + posePhase)
    //      s = (x, y, z, roll, pitch, yaw), lengths in model units, angles in deg
    PoseMask ikSpec{true, true, true, false, false, false};   // exactly 3 true
    std::optional<Vec6> pose0;     // empty -> the start pose reached by phi0
    Vec6 poseAmp = (Vec6() << 1.0, 1.0, 0.4, 0, 0, 0).finished();
    Vec6 posePhaseDeg = (Vec6() << 0, 90, 0, 0, 0, 0).finished();

    // ---- configuration of every top plate at the start: 1 = highest, 2 = next ...
    int topAssembly = 1;

    // ---- output
    std::string csvPath = "stewart_frames.csv";
};

// Runs the whole simulation and prints a report. Returns 0 on success.
// Throws std::exception on invalid input or if the start pose cannot be built.
int run(const Config& cfg);

}  // namespace stewart
