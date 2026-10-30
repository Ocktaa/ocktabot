// =============================================================================
// math_utils.cpp  -  see math_utils.hpp for what each function is for
// =============================================================================
#include "math_utils.hpp"

#include <Eigen/Eigenvalues>
#include <algorithm>
#include <complex>

namespace stewart {

double angWrap(double a) {
    // MATLAB: mod(a + pi, 2*pi) - pi.  MATLAB's mod rounds DOWN (floor), so we
    // must use std::floor here. std::fmod rounds toward zero and would return
    // negative values for negative inputs (e.g. -200 deg would stay -200 deg).
    const double twoPi = 2.0 * PI;
    return a - twoPi * std::floor((a + PI) / twoPi);
}

Vec3 wvec(double beta, double phi) {
    return Vec3(std::cos(beta) * std::cos(phi),
                std::sin(beta) * std::cos(phi),
                std::sin(phi));
}

Vec3 dwvec(double beta, double phi) {
    return Vec3(-std::cos(beta) * std::sin(phi),
                -std::sin(beta) * std::sin(phi),
                 std::cos(phi));
}

RotationAndDerivatives rotZYX(const Vec3& a) {
    const double cr = std::cos(a[0]), sr = std::sin(a[0]);   // roll  (about x)
    const double cp = std::cos(a[1]), sp = std::sin(a[1]);   // pitch (about y)
    const double cy = std::cos(a[2]), sy = std::sin(a[2]);   // yaw   (about z)

    // Basic rotations (comma initializer fills the matrix ROW by ROW).
    Mat3 Rx, Ry, Rz;
    Rx << 1,   0,   0,
          0,  cr, -sr,
          0,  sr,  cr;
    Ry <<  cp, 0, sp,
            0, 1,  0,
          -sp, 0, cp;
    Rz << cy, -sy, 0,
          sy,  cy, 0,
           0,   0, 1;

    // Their derivatives with respect to their own angle.
    Mat3 dRx, dRy, dRz;
    dRx << 0,   0,   0,
           0, -sr, -cr,
           0,  cr, -sr;
    dRy << -sp, 0,  cp,
             0, 0,   0,
           -cp, 0, -sp;
    dRz << -sy, -cy, 0,
            cy, -sy, 0,
             0,   0, 0;

    RotationAndDerivatives out;
    out.Q = Rz * Ry * Rx;
    // Each angle appears in only one factor -> differentiate only that factor.
    out.dQ[0] = Rz * Ry * dRx;   // d/droll
    out.dQ[1] = Rz * dRy * Rx;   // d/dpitch
    out.dQ[2] = dRz * Ry * Rx;   // d/dyaw
    return out;
}

Vec6 poseVector(const Mat3& Q, const Vec3& c) {
    // MATLAB (1-based): roll = atan2(Q(3,2), Q(3,3)), pitch = asin(-Q(3,1)),
    //                   yaw  = atan2(Q(2,1), Q(1,1)).  Below: 0-based indices.
    const double sinPitch = std::clamp(-Q(2, 0), -1.0, 1.0);   // guard round-off
    Vec6 s;
    s << c,
         std::atan2(Q(2, 1), Q(2, 2)),   // roll
         std::asin(sinPitch),            // pitch
         std::atan2(Q(1, 0), Q(0, 0));   // yaw
    return s;
}

RigidTransform fitRigid(const Mat3& A, const Mat3& B) {
    // 1. centroids of both point sets
    const Vec3 ca = A.rowwise().mean();
    const Vec3 cb = B.rowwise().mean();
    // 2. cross-covariance of the centered points
    const Mat3 H = (A.colwise() - ca) * (B.colwise() - cb).transpose();
    // 3. SVD:  H = U * S * V^T
    Eigen::JacobiSVD<Mat3> svd(H, Eigen::ComputeFullU | Eigen::ComputeFullV);
    const Mat3 U = svd.matrixU();
    const Mat3 V = svd.matrixV();
    // 4. force a PROPER rotation (det = +1, never a mirror image)
    const double d = ((V * U.transpose()).determinant() < 0.0) ? -1.0 : 1.0;
    const Mat3 D = Vec3(1.0, 1.0, d).asDiagonal();

    RigidTransform t;
    t.Q = V * D * U.transpose();
    t.p = cb - t.Q * ca;
    return t;
}

std::vector<double> realRoots(const std::vector<double>& c) {
    // ---- 1. drop exact-zero coefficients of the HIGHEST powers (degree falls)
    int hi = static_cast<int>(c.size()) - 1;
    while (hi >= 0 && c[hi] == 0.0) --hi;
    if (hi < 1) return {};   // zero or constant polynomial: no roots

    // ---- 2. exact-zero coefficients of the LOWEST powers are roots at x = 0
    int lo = 0;
    while (c[lo] == 0.0) ++lo;
    std::vector<std::complex<double>> all(lo, std::complex<double>(0.0, 0.0));

    // ---- 3. the remaining polynomial c[lo..hi] via its companion matrix
    //   For  a_n x^n + ... + a_1 x + a_0  (here a_n = c[hi]) the companion
    //   matrix has first row  -a_(n-1)/a_n, ..., -a_0/a_n  and ones on the
    //   sub-diagonal. Its eigenvalues are the roots. (MATLAB's roots() does
    //   exactly this.)
    const int deg = hi - lo;
    if (deg >= 1) {
        MatX C = MatX::Zero(deg, deg);
        for (int j = 0; j < deg; ++j) C(0, j) = -c[hi - 1 - j] / c[hi];
        for (int i = 1; i < deg; ++i) C(i, i - 1) = 1.0;
        Eigen::EigenSolver<MatX> es(C, /*computeEigenvectors=*/false);
        for (int i = 0; i < deg; ++i) all.push_back(es.eigenvalues()[i]);
    }

    // ---- 4. keep the (numerically) real ones
    std::vector<double> out;
    for (const auto& z : all) {
        if (std::abs(z.imag()) < 1e-4 * std::max(1.0, std::abs(z))) out.push_back(z.real());
    }
    return out;
}

}  // namespace stewart
