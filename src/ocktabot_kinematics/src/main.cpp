// =============================================================================
// main.cpp  -  STACKED STAGES WITH LOCKED LEGS (C++ port of stewart_stacked.m)
// -----------------------------------------------------------------------------
// This file is only the "USER INPUTS" block. Edit the values below; the work is
// done by run() in simulation.cpp.
//
// Build:   cmake -S . -B build && cmake --build build
// Run:     ./build/stewart_stacked                 (driveMode from below)
//          ./build/stewart_stacked pose            (override driveMode)
//          ./build/stewart_stacked inputs out.csv  (override output file)
// Plot:    python3 plot_frames.py stewart_frames.csv
//
// The defaults reproduce the MATLAB script: an equilateral hinge triangle at
// radius 4 (the six old points reduce to exactly these corners), links of
// length 3 swinging toward the centroid, two stacked stages.
// =============================================================================
#include <cmath>
#include <cstdio>
#include <exception>
#include <string>

#include "simulation.hpp"

using namespace stewart;

int main(int argc, char** argv) {
    Config cfg;

    // ---------------------------------------------------------------- geometry
    cfg.nStages = 2;

    // BASE = bottom of stage 1, in WORLD coordinates.
    const double r3 = 2.0 * std::sqrt(3.0);   // 2*sqrt(3) = 3.4641
    cfg.base.R = Vec2(0.0, 4.0);
    cfg.base.S = Vec2(-r3, -2.0);
    cfg.base.T = Vec2(r3, -2.0);
    cfg.base.m = Vec3(3.0, 3.0, 3.0);          // link lengths
    cfg.base.deltaDeg = Vec3(0.0, 0.0, 0.0);   // 0 = links swing toward the centroid

    // Top plates in their OWN frames. An empty entry means "same as the base".
    // Example of a different top plate for stage 2:
    //   PlateInput t = cfg.base;  t.m = Vec3(2.5, 2.5, 2.5);  cfg.tops = {std::nullopt, t};
    cfg.tops = {};

    // Link lengths of the bottom of stage k >= 2 (hinged on top[k-1]).
    // Empty -> same as top[k-1].m. Index 0 is unused (that is the base).
    cfg.botM = {};

    // 'Straight': top link + next bottom link form one straight bar
    // 'Mirror'  : next bottom link at the mirrored angle
    cfg.coupling = Coupling::Straight;

    // ------------------------------------------------------- what drives motion
    // Inputs: you prescribe the three base angles
    // Pose  : you prescribe 3 pose values of the LAST plate; the IK finds the rest
    cfg.drive = DriveMode::Inputs;

    // ---- DriveMode::Inputs   phi(t) = phi0 + phiAmp * sin(tau + phiPhase)  [deg]
    cfg.phi0Deg = std::nullopt;   // nullopt -> stage-1 joints level at height h0
    cfg.h0 = 2.4;
    cfg.phiAmpDeg = Vec3(10.0, 10.0, 10.0);
    cfg.phiPhaseDeg = Vec3(0.0, 120.0, 240.0);
    cfg.nFrames = 180;

    // ---- DriveMode::Pose   s(t) = pose0 + poseAmp * sin(tau + posePhase)
    //      s = (x, y, z, roll, pitch, yaw), lengths in model units, angles in deg
    cfg.ikSpec = {true, true, true, false, false, false};   // prescribe x, y, z
    cfg.pose0 = std::nullopt;                               // nullopt -> start pose
    cfg.poseAmp << 1.0, 1.0, 0.4, 0.0, 0.0, 0.0;            // circle in x-y + bob in z
    cfg.posePhaseDeg << 0.0, 90.0, 0.0, 0.0, 0.0, 0.0;

    // Configuration of every top plate at the start: 1 = highest, 2 = next ...
    cfg.topAssembly = 1;

    cfg.csvPath = "stewart_frames.csv";

    // ------------------------------------------------- command-line overrides
    if (argc > 1) {
        const std::string mode = argv[1];
        if (mode == "inputs") cfg.drive = DriveMode::Inputs;
        else if (mode == "pose") cfg.drive = DriveMode::Pose;
        else {
            std::fprintf(stderr, "usage: %s [inputs|pose] [output.csv]\n", argv[0]);
            return 2;
        }
    }
    if (argc > 2) cfg.csvPath = argv[2];

    try {
        return run(cfg);
    } catch (const std::exception& e) {
        std::fprintf(stderr, "error: %s\n", e.what());
        return 1;
    }
}
