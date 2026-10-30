// =============================================================================
// direct_kinematics.cpp  -  see direct_kinematics.hpp for the big picture
// =============================================================================
#include "direct_kinematics.hpp"

#include <algorithm>

namespace stewart {

using cplx = std::complex<double>;

// Polynomials with complex coefficients in DESCENDING powers (like MATLAB's
// conv): {a0, a1, a2} means a0 x^2 + a1 x + a2.
using CPoly3 = std::array<cplx, 3>;   // quadratic
using CPoly5 = std::array<cplx, 5>;   // quartic

// Product of two quadratics -> quartic (MATLAB: conv(a, b)).
static CPoly5 conv(const CPoly3& a, const CPoly3& b) {
    CPoly5 r{};   // value-initialised: all zeros
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) r[i + j] += a[i] * b[j];
    return r;
}

Coeffs5 pairCoeffs(const Vec3& Oa, const Vec3& Ob, double ma, double mb,
                   double ba, double bb, double len) {
    // Only the in-plane offset between the two hinge corners matters.
    const double dx = Oa.x() - Ob.x();
    const double dy = Oa.y() - Ob.y();
    return {
         2.0 * ma * (std::cos(ba) * dx + std::sin(ba) * dy),   // * cos(pa)
        -2.0 * mb * (std::cos(bb) * dx + std::sin(bb) * dy),   // * cos(pb)
        -2.0 * ma * mb * std::cos(ba - bb),                    // * cos(pa)cos(pb)
        -2.0 * ma * mb,                                        // * sin(pa)sin(pb)
         dx * dx + dy * dy + ma * ma + mb * mb - len * len     // constant
    };
}

Coeffs5 halfAngle(const Coeffs5& C) {
    // Paper p.442 (G from D; the same rule gives H from E and I from F).
    return {
        -C[0] - C[1] + C[2] + C[4],   // xa^2 xb^2
         C[0] - C[1] - C[2] + C[4],   //      xb^2
         4.0 * C[3],                  // xa   xb
        -C[0] + C[1] - C[2] + C[4],   // xa^2
         C[0] + C[1] + C[2] + C[4]    // 1
    };
}

cplx resultantAt(cplx xr, const Coeffs5& G, const Coeffs5& H, const Coeffs5& I) {
    // ---- eq. (9): quadratic in x_S, numeric coefficients at this x_R
    //      a1 x_S^2 + b1 x_S + c1 = 0
    const cplx a1 = G[0] * xr * xr + G[1];
    const cplx b1 = G[2] * xr;
    const cplx c1 = G[3] * xr * xr + G[4];

    // ---- eq. (10): quadratic in x_S whose coefficients are quadratics in x_T
    //      a2(x_T) x_S^2 + b2(x_T) x_S + c2(x_T) = 0
    const CPoly3 a2{H[0], 0.0, H[3]};   // H0 x_T^2 + H3
    const CPoly3 b2{0.0, H[2], 0.0};    // H2 x_T
    const CPoly3 c2{H[1], 0.0, H[4]};   // H1 x_T^2 + H4

    // ---- Bezout resultant of the two quadratics in x_S (eq. 12):
    //      (a1 c2 - c1 a2)^2 - (a1 b2 - b1 a2)(b1 c2 - c1 b2)   -> quartic in x_T
    CPoly3 u, p, q;
    for (int i = 0; i < 3; ++i) {
        u[i] = a1 * c2[i] - c1 * a2[i];
        p[i] = a1 * b2[i] - b1 * a2[i];
        q[i] = b1 * c2[i] - c1 * b2[i];
    }
    const CPoly5 uu = conv(u, u);
    const CPoly5 pq = conv(p, q);
    CPoly5 Jq;   // the paper's J1..J5 (eq. 13), descending powers of x_T
    for (int i = 0; i < 5; ++i) Jq[i] = uu[i] - pq[i];

    // ---- eq. (11)/(14): quadratic in x_T at this x_R
    const CPoly3 M{I[0] * xr * xr + I[3], I[2] * xr, I[1] * xr * xr + I[4]};

    // ---- Sylvester matrix of (quartic, quadratic) in x_T:
    //      2 shifted copies of the quartic, 4 shifted copies of the quadratic.
    //      Its determinant is zero iff both share a root x_T (eq. 15).
    Eigen::Matrix<cplx, 6, 6> Syl = Eigen::Matrix<cplx, 6, 6>::Zero();
    for (int i = 0; i < 5; ++i) {
        Syl(0, i) = Jq[i];
        Syl(1, i + 1) = Jq[i];
    }
    for (int r = 0; r < 4; ++r)
        for (int i = 0; i < 3; ++i) Syl(2 + r, r + i) = M[i];

    return Syl.determinant();
}

std::array<double, 17> resultantPoly(const Coeffs5& G, const Coeffs5& H, const Coeffs5& I) {
    // The eliminant has degree <= 16. Sampling it at N = 32 points z_k on the
    // unit circle and applying the inverse DFT gives its coefficients exactly
    // (up to round-off). MATLAB: c = fft(v) / N.
    constexpr int N = 32;
    std::array<cplx, N> v;
    for (int k = 0; k < N; ++k) {
        const cplx zk = std::polar(1.0, 2.0 * PI * k / N);   // e^(2 pi i k / N)
        v[k] = resultantAt(zk, G, H, I);
    }

    // A plain O(N^2) DFT: 32 x 17 terms, no FFT library needed.
    std::array<double, 17> coef{};
    double maxAbs = 0.0;
    for (int n = 0; n <= 16; ++n) {
        cplx sum(0.0, 0.0);
        for (int k = 0; k < N; ++k) sum += v[k] * std::polar(1.0, -2.0 * PI * k * n / N);
        coef[n] = (sum / static_cast<double>(N)).real();   // imaginary part is round-off
        maxAbs = std::max(maxAbs, std::abs(coef[n]));
    }
    // Zero coefficients that are pure round-off relative to the largest one.
    for (double& c : coef)
        if (std::abs(c) < 1e-12 * maxAbs) c = 0.0;
    return coef;
}

TrigEqValue trigEq(const Coeffs5& C, double pa, double pb) {
    const double ca = std::cos(pa), sa = std::sin(pa);
    const double cb = std::cos(pb), sb = std::sin(pb);
    TrigEqValue r;
    r.f  =  C[0] * ca + C[1] * cb + C[2] * ca * cb + C[3] * sa * sb + C[4];
    r.da = -C[0] * sa - C[2] * sa * cb + C[3] * ca * sb;
    r.db = -C[1] * sb - C[2] * ca * sb + C[3] * sa * cb;
    return r;
}

void phiEqs(const Vec3& phi, const Coeffs5& D, const Coeffs5& E, const Coeffs5& F,
            Vec3& f, Mat3& J) {
    const TrigEqValue e1 = trigEq(D, phi[0], phi[1]);   // eq. (6): R-S
    const TrigEqValue e2 = trigEq(E, phi[1], phi[2]);   // eq. (7): S-T
    const TrigEqValue e3 = trigEq(F, phi[2], phi[0]);   // eq. (8): T-R
    f << e1.f, e2.f, e3.f;
    J << e1.da, e1.db,   0.0,
           0.0, e2.da, e2.db,
         e3.db,   0.0, e3.da;
}

Vec3 polishPhi(Vec3 phi, const Coeffs5& D, const Coeffs5& E, const Coeffs5& F) {
    Vec3 f;
    Mat3 J;
    for (int it = 0; it < 30; ++it) {
        phiEqs(phi, D, E, F, f, J);
        Eigen::PartialPivLU<Mat3> lu(J);
        // Stop if J is (nearly) singular. Written as !(rc >= tol) so it also
        // stops when rc is NaN.
        if (!(lu.rcond() >= 1e-14)) break;
        const Vec3 dphi = -lu.solve(f);   // Newton step:  J * dphi = -f
        phi += dphi;
        if (dphi.norm() < 1e-14) break;
    }
    return phi;
}

std::vector<DKSolution> stewartDK(const Stage& plate, const Vec3& b) {
    const Mat3& O = plate.O;
    const Vec3& m = plate.m;
    const Vec3& be = plate.beta;

    // ---- 1. one trig equation per pair of links ------------------------------
    const Coeffs5 D = pairCoeffs(O.col(0), O.col(1), m[0], m[1], be[0], be[1], b[0]);  // R-S
    const Coeffs5 E = pairCoeffs(O.col(1), O.col(2), m[1], m[2], be[1], be[2], b[1]);  // S-T
    const Coeffs5 F = pairCoeffs(O.col(2), O.col(0), m[2], m[0], be[2], be[0], b[2]);  // T-R

    // ---- 2. half-angle form -------------------------------------------------
    const Coeffs5 G = halfAngle(D);
    const Coeffs5 H = halfAngle(E);
    const Coeffs5 I = halfAngle(F);

    // ---- 3. degree-16 polynomial in x_R and its real roots ---------------------
    const std::array<double, 17> coef = resultantPoly(G, H, I);
    const std::vector<double> xrList = realRoots(std::vector<double>(coef.begin(), coef.end()));

    const double tol = 1e-7 * b.maxCoeff();   // accepted error on the triangle sides
    std::vector<DKSolution> out;

    for (const double xR : xrList) {
        // ---- 4. back-substitution: x_T from eq. (11), x_S from eq. (9) -----------
        // realRoots wants ASCENDING powers: {constant, x, x^2}.
        const std::vector<double> xtList = realRoots(
            {I[1] * xR * xR + I[4], I[2] * xR, I[0] * xR * xR + I[3]});
        const std::vector<double> xsList = realRoots(
            {G[3] * xR * xR + G[4], G[2] * xR, G[0] * xR * xR + G[1]});

        // Not every (x_S, x_T) combination is valid; the side check below
        // throws away the wrong pairings.
        for (const double xS : xsList) {
            for (const double xT : xtList) {
                // ---- 5. back to angles, then refine with Newton -----------------
                Vec3 phi(2.0 * std::atan(xR), 2.0 * std::atan(xS), 2.0 * std::atan(xT));
                phi = polishPhi(phi, D, E, F);

                // ---- 6. does it really reproduce the three sides? ----------------
                const Mat3 P = jointPositions(plate, phi);
                const double err = std::max({
                    std::abs((P.col(0) - P.col(1)).norm() - b[0]),
                    std::abs((P.col(1) - P.col(2)).norm() - b[1]),
                    std::abs((P.col(2) - P.col(0)).norm() - b[2])});
                if (!phi.allFinite() || !(err < tol)) continue;

                // ---- 7. drop duplicates (same angles up to 1e-6 rad) --------------
                phi = angWrapVec(phi);
                bool isNew = true;
                for (const DKSolution& s : out) {
                    if (angWrapVec(s.phi - phi).cwiseAbs().maxCoeff() <= 1e-6) {
                        isNew = false;
                        break;
                    }
                }
                if (isNew) out.push_back({phi, P});
            }
        }
    }
    return out;
}

}  // namespace stewart
