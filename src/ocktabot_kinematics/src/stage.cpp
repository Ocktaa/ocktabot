// =============================================================================
// stage.cpp  -  see stage.hpp
// =============================================================================
#include "stage.hpp"

#include <stdexcept>

namespace stewart {

Stage stageFromPoints(const Vec2& R, const Vec2& S, const Vec2& T,
                      const Vec3& m, const Vec3& delta) {
    // ---- 1. the three corners must form a real triangle -----------------------
    // The 2D cross product of two edges is twice the triangle's signed area:
    //   area2 = |a| |b| sin(angle at R).
    // It is zero exactly when the points are collinear or two coincide.
    // Dividing by |a||b| makes the test independent of units (mm vs m).
    // The sign only tells the winding (CCW > 0), which does not matter here.
    const Vec2 a = S - R;
    const Vec2 b = T - R;
    const double area2 = a.x() * b.y() - a.y() * b.x();
    const double na = a.norm(), nb = b.norm();
    if (na == 0.0 || nb == 0.0 || std::abs(area2) <= 1e-6 * na * nb) {
        throw std::invalid_argument("stageFromPoints: R, S, T are collinear or coincident");
    }
    if ((m.array() <= 0.0).any()) {
        throw std::invalid_argument("stageFromPoints: every link length m must be > 0");
    }

    Stage st;
    // ---- 2. hinge corners, lifted into the plate plane z = 0 -----------------
    st.O.col(0) = Vec3(R.x(), R.y(), 0.0);
    st.O.col(1) = Vec3(S.x(), S.y(), 0.0);
    st.O.col(2) = Vec3(T.x(), T.y(), 0.0);
    st.m = m;

    // ---- 3. swing directions and hinge axes -----------------------------------
    // beta_j = direction from corner j toward the centroid, plus delta_j.
    // atan2 (not atan) gives the correct angle in all four quadrants, so
    // negative coordinates need no special handling.
    const Vec3 c = st.O.rowwise().mean();
    for (int j = 0; j < 3; ++j) {
        st.beta[j] = std::atan2(c.y() - st.O(1, j), c.x() - st.O(0, j)) + delta[j];
        // hinge axis: in the plate plane, perpendicular to the swing direction
        st.u.col(j) = Vec3(-std::sin(st.beta[j]), std::cos(st.beta[j]), 0.0);
    }
    return st;
}

Mat3 jointPositions(const Stage& plate, const Vec3& phi) {
    Mat3 P;
    for (int j = 0; j < 3; ++j) {
        P.col(j) = plate.O.col(j) + plate.m[j] * wvec(plate.beta[j], phi[j]);
    }
    return P;
}

bool sameStage(const Stage& a, const Stage& b) {
    return a.O == b.O && a.m == b.m && a.beta == b.beta;
}

}  // namespace stewart
