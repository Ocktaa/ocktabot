// =============================================================================
// math_utils.hpp  -  small math helpers used by every other file
// -----------------------------------------------------------------------------
// MATLAB origin: angWrap, wvec, dwvec, rotZYX, poseVector, fitRigid, roots().
//
// Conventions used in the WHOLE project:
//   * All angles are in RADIANS internally. Convert degrees only at the edges
//     (user inputs and printed output) with deg2rad / rad2deg.
//   * A set of three points R, S, T is stored as a Mat3 whose COLUMNS are the
//     points (column 0 = R, column 1 = S, column 2 = T), exactly like MATLAB's
//     [R S T].
//   * A pose is a Vec6 s = (x, y, z, roll, pitch, yaw), where (x, y, z) is the
//     centroid of the plate's hinge corners and Q = Rz(yaw) * Ry(pitch) * Rx(roll).
// =============================================================================
#pragma once

#include <Eigen/Dense>
#include <array>
#include <cmath>
#include <vector>

namespace stewart {

// ---- Eigen type aliases (fixed-size types are fast and allocation-free) ----
using Vec2 = Eigen::Vector2d;
using Vec3 = Eigen::Vector3d;
using Mat3 = Eigen::Matrix3d;
using Vec6 = Eigen::Matrix<double, 6, 1>;
using VecX = Eigen::VectorXd;   // dynamic size: the 9N-long IK vector
using MatX = Eigen::MatrixXd;   // dynamic size: the 9N x 9N IK Jacobian

constexpr double PI  = 3.14159265358979323846;
constexpr double DEG = PI / 180.0;   // multiply degrees by DEG to get radians

inline double deg2rad(double d) { return d * DEG; }
inline double rad2deg(double r) { return r / DEG; }

// -----------------------------------------------------------------------------
// angWrap: wrap an angle into [-pi, pi).
//   angWrap(190 deg) = -170 deg,  angWrap(-200 deg) = 160 deg.
// Used whenever two angles are COMPARED, so that 179 deg and -179 deg count
// as 2 deg apart instead of 358 deg.
// -----------------------------------------------------------------------------
double angWrap(double a);

// Element-wise angWrap for any Eigen vector or expression, e.g.
//   angWrapVec(phiNew - phiOld)
// (A template instead of overloads, so Eigen expressions don't become ambiguous.)
template <typename Derived>
typename Derived::PlainObject angWrapVec(const Eigen::MatrixBase<Derived>& a) {
    return a.unaryExpr([](double v) { return angWrap(v); });
}

// -----------------------------------------------------------------------------
// wvec: eq. (1) of the paper - unit direction of a link.
//   beta = direction in the plate plane the link swings toward
//   phi  = elevation of the link above the plate (0 = flat along beta,
//          90 deg = straight up along the plate normal)
//   w = (cos(beta) cos(phi), sin(beta) cos(phi), sin(phi))
// -----------------------------------------------------------------------------
Vec3 wvec(double beta, double phi);

// dwvec: derivative of wvec with respect to phi (used in the IK Jacobian).
Vec3 dwvec(double beta, double phi);

// -----------------------------------------------------------------------------
// rotZYX: rotation matrix from roll, pitch, yaw, plus its three derivatives.
//   Input  a = (roll, pitch, yaw)                     [rad]
//   Output Q     = Rz(yaw) * Ry(pitch) * Rx(roll)
//          dQ[0] = dQ/droll, dQ[1] = dQ/dpitch, dQ[2] = dQ/dyaw
// A point q in plate coordinates lands in the world at  Q * q + (x, y, z).
// -----------------------------------------------------------------------------
struct RotationAndDerivatives {
    Mat3 Q;
    std::array<Mat3, 3> dQ;
};
RotationAndDerivatives rotZYX(const Vec3& a);

// -----------------------------------------------------------------------------
// poseVector: inverse of rotZYX. Builds s = (x, y, z, roll, pitch, yaw) from a
// rotation Q and a centroid c. Ambiguous only at pitch = +-90 deg (gimbal lock).
// -----------------------------------------------------------------------------
Vec6 poseVector(const Mat3& Q, const Vec3& c);

// -----------------------------------------------------------------------------
// fitRigid: Kabsch algorithm. Finds the proper rotation Q and translation p
// that best map the columns of A onto the columns of B:   B ~= Q * A + p.
// Here A and B are the same three joints seen in two different frames, so the
// fit is exact; it gives us the pose of a plate.
// -----------------------------------------------------------------------------
struct RigidTransform {
    Mat3 Q;
    Vec3 p;
};
RigidTransform fitRigid(const Mat3& A, const Mat3& B);

// -----------------------------------------------------------------------------
// realRoots: the REAL roots of a polynomial, like MATLAB's roots() followed by
// the filter used in stewartDK.
//   coefAscending[i] = coefficient of x^i   (NOTE: ascending powers!)
//   Exact-zero leading coefficients are dropped (degree falls), exact-zero
//   trailing coefficients give roots at x = 0, the rest come from the
//   eigenvalues of the companion matrix (the same method MATLAB uses).
//   A complex root z is kept as real if |imag(z)| < 1e-4 * max(1, |z|).
// -----------------------------------------------------------------------------
std::vector<double> realRoots(const std::vector<double>& coefAscending);

}  // namespace stewart
