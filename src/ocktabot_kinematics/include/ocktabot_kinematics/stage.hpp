// =============================================================================
// stage.hpp  -  one plate's set of three hinges, and where its links end
// -----------------------------------------------------------------------------
// Replaces the MATLAB functions stageFromRows / stageGeometry / baseGeometry /
// legPairs / equivalentArms. The old code started from six joint points and six
// leg lengths and immediately reduced every leg PAIR to one hinged link. Here a
// plate is defined directly by what the kinematics actually uses:
//
//   O_j    hinge corner j on the plate (j = 0, 1, 2  <->  R, S, T)
//   m_j    length of the link hinged at that corner
//   beta_j direction in the plate plane the link swings toward
//   u_j    hinge axis, perpendicular to beta_j (used for drawing and checks)
//
// Everything is expressed in the plate's OWN frame, with the plate in z = 0.
// =============================================================================
#pragma once

#include "math_utils.hpp"

namespace stewart {

struct Stage {
    Mat3 O;      // columns: hinge corners R, S, T (z = 0)
    Vec3 m;      // link lengths m_R, m_S, m_T
    Vec3 beta;   // swing directions [rad], angle from the plate's +x axis
    Mat3 u;      // columns: hinge axes, u_j = (-sin beta_j, cos beta_j, 0)
};

// -----------------------------------------------------------------------------
// stageFromPoints: build a plate from its three hinge corners.
//   R, S, T : hinge corners (x, y) in the plate's own frame
//             - for the base these are WORLD coordinates
//             - for a top plate they define that plate's frame; give every
//               plate the same layout as the base if you want identical
//               stages to report yaw = 0 at home
//   m       : link lengths, all > 0
//   delta   : [rad] offset of each beta from "pointing at the centroid".
//             delta = 0 -> the link swings straight toward the centroid.
//             delta > 0 turns it counter-clockwise (seen from the plate's +z).
// Throws std::invalid_argument if the corners are collinear/coincident or a
// link length is not positive.
// -----------------------------------------------------------------------------
Stage stageFromPoints(const Vec2& R, const Vec2& S, const Vec2& T,
                      const Vec3& m, const Vec3& delta);

// -----------------------------------------------------------------------------
// jointPositions: eq. (2) of the paper. Free ends of the three links:
//   P_j = O_j + m_j * wvec(beta_j, phi_j)
// Returns a Mat3 whose columns are the joints R, S, T in the plate's frame.
// -----------------------------------------------------------------------------
Mat3 jointPositions(const Stage& plate, const Vec3& phi);

// True if two plates have exactly the same O, m and beta.
bool sameStage(const Stage& a, const Stage& b);

}  // namespace stewart
