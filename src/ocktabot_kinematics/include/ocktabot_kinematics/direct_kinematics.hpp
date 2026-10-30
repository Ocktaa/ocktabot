// =============================================================================
// direct_kinematics.hpp  -  the paper's direct kinematics of ONE plate
// -----------------------------------------------------------------------------
// Nanua, Waldron, Murthy, "Direct Kinematic Solution of a Stewart Platform",
// IEEE Trans. Robotics & Automation 6(4), 1990, eqs. (3)-(16).
//
// The question this answers:
//   "A plate has three links hinged at its corners. Their free ends must form
//    a triangle with sides b = (|RS|, |ST|, |TR|). Which link angles
//    phi = (phi_R, phi_S, phi_T) make that happen?"
//
// How (call order inside stewartDK):
//   pairCoeffs   one trig equation per pair of links: (R,S), (S,T), (T,R)
//   halfAngle    rewrite each with x = tan(phi/2) -> polynomial equations
//   resultantPoly / resultantAt
//                eliminate x_S and x_T -> ONE polynomial of degree 16 in x_R
//   realRoots    its real roots = candidate x_R
//   back-substitute x_T, x_S, convert to angles, refine with polishPhi,
//   keep the ones that really reproduce the sides b, drop duplicates.
// Up to 16 solutions ("assembly modes") can exist.
// =============================================================================
#pragma once

#include <array>
#include <complex>
#include <vector>

#include "stage.hpp"

namespace stewart {

// Five coefficients of one pair equation (D, E, F in the paper), or of its
// half-angle form (G, H, I in the paper). Index 0 = paper's index 1.
using Coeffs5 = std::array<double, 5>;

// One assembly configuration found by stewartDK.
struct DKSolution {
    Vec3 phi;   // link angles phi_R, phi_S, phi_T [rad], wrapped to [-pi, pi)
    Mat3 P;     // columns: joints R, S, T in the PLATE's frame
};

// -----------------------------------------------------------------------------
// pairCoeffs: eqs. (6)-(8). For links a and b (hinged at Oa, Ob) whose ends must
// be `len` apart, the condition |P_a - P_b|^2 = len^2 becomes
//   C0 cos(pa) + C1 cos(pb) + C2 cos(pa)cos(pb) + C3 sin(pa)sin(pb) + C4 = 0
// -----------------------------------------------------------------------------
Coeffs5 pairCoeffs(const Vec3& Oa, const Vec3& Ob, double ma, double mb,
                   double ba, double bb, double len);

// -----------------------------------------------------------------------------
// halfAngle: substitute cos = (1-x^2)/(1+x^2), sin = 2x/(1+x^2), x = tan(phi/2)
// and clear denominators:
//   (G0 xa^2 + G1) xb^2 + G2 xa xb + (G3 xa^2 + G4) = 0
// -----------------------------------------------------------------------------
Coeffs5 halfAngle(const Coeffs5& C);

// -----------------------------------------------------------------------------
// resultantAt: value of the eliminant polynomial at ONE (complex) x_R.
//   Step 1: eq. (9) and eq. (10) are both quadratics in x_S. Their Bezout
//           resultant removes x_S and leaves a quartic in x_T (eq. 13).
//   Step 2: that quartic and eq. (11) (a quadratic in x_T) share a root only if
//           their 6x6 Sylvester determinant is zero -> removes x_T (eq. 15).
// Must use COMPLEX arithmetic: it is evaluated at complex roots of unity.
// -----------------------------------------------------------------------------
std::complex<double> resultantAt(std::complex<double> xr, const Coeffs5& G,
                                 const Coeffs5& H, const Coeffs5& I);

// -----------------------------------------------------------------------------
// resultantPoly: the degree-16 polynomial in x_R, recovered from its values at
// the 32 complex roots of unity (a discrete Fourier transform turns the values
// back into coefficients). This avoids expanding the paper's long symbolic
// formulas. Returns 17 coefficients in ASCENDING powers (coef[i] -> x_R^i).
// -----------------------------------------------------------------------------
std::array<double, 17> resultantPoly(const Coeffs5& G, const Coeffs5& H, const Coeffs5& I);

// -----------------------------------------------------------------------------
// trigEq: one pair equation and its two partial derivatives.
// phiEqs: all three pair equations f(phi) = 0 and their 3x3 Jacobian.
// polishPhi: Newton's method on phiEqs to clean up round-off of a solution.
// -----------------------------------------------------------------------------
struct TrigEqValue {
    double f;    // value of the equation
    double da;   // df/d(pa)
    double db;   // df/d(pb)
};
TrigEqValue trigEq(const Coeffs5& C, double pa, double pb);

void phiEqs(const Vec3& phi, const Coeffs5& D, const Coeffs5& E, const Coeffs5& F,
            Vec3& f, Mat3& J);

Vec3 polishPhi(Vec3 phi, const Coeffs5& D, const Coeffs5& E, const Coeffs5& F);

// -----------------------------------------------------------------------------
// stewartDK: ALL real assembly configurations of `plate` whose link ends form
// a triangle with sides b = (|RS|, |ST|, |TR|). Results are in the plate's own
// frame. The list may be empty (the plate cannot reach that triangle).
// Known blind spot (same as the MATLAB code): x = tan(phi/2) cannot represent
// phi = +-180 deg exactly.
// -----------------------------------------------------------------------------
std::vector<DKSolution> stewartDK(const Stage& plate, const Vec3& b);

}  // namespace stewart
