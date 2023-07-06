//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "PointEvaluation.hpp"
#include "RBFInterpolation.hpp"

const double eps = 1e-10;

TEST_CASE("Gaussian RBF, epsilon=0.1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0.990049833749, 0.993620436379, 0.996406472231, 0.998401279318, 0.999600079989,
                               1., 0.999600079989, 0.998401279318, 0.996406472231, 0.993620436379, 0.990049833749};

    auto gaussian = rbf::gaussian(0.1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Gaussian RBF, epsilon=1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0.367879441171, 0.527292424043, 0.697676326071, 0.852143788966, 0.960789439152, 1.,
                               0.960789439152, 0.852143788966, 0.697676326071, 0.527292424043, 0.367879441171};

    auto gaussian = rbf::gaussian(1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Multi-quadric RBF, epsilon=0.1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {1.00498756211, 1.00319489632, 1.00179838291, 1.00079968026, 1.00019998, 1., 1.00019998,
                               1.00079968026, 1.00179838291, 1.00319489632, 1.00498756211};

    auto gaussian = rbf::multiquadric(0.1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Multi-quadric RBF, epsilon=1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {1.41421356237, 1.28062484749, 1.16619037897, 1.07703296143, 1.01980390272, 1.,
                               1.01980390272, 1.07703296143, 1.16619037897, 1.28062484749, 1.41421356237};

    auto gaussian = rbf::multiquadric(1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Inverse multi-quadric RBF, epsilon=0.1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0.99503719021, 0.996815278536, 0.998204845466, 0.999200958722, 0.99980005998, 1.,
                               0.99980005998, 0.999200958722, 0.998204845466, 0.996815278536, 0.99503719021};

    auto gaussian = rbf::inverse_multiquadric(0.1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Inverse multi-quadric RBF, epsilon=1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0.707106781187, 0.780868809443, 0.857492925713, 0.928476690885, 0.980580675691, 1.,
                               0.980580675691, 0.928476690885, 0.857492925713, 0.780868809443, 0.707106781187};

    auto gaussian = rbf::inverse_multiquadric(1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Inverse quadric RBF, epsilon=0.1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0.990099009901, 0.993640699523, 0.996412913511, 0.998402555911, 0.999600159936, 1.,
                               0.999600159936, 0.998402555911, 0.996412913511, 0.993640699523, 0.990099009901};

    auto gaussian = rbf::inverse_quadric(0.1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Inverse quadric RBF, epsilon=1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0.5, 0.609756097561, 0.735294117647, 0.862068965517, 0.961538461538, 1., 0.961538461538,
                               0.862068965517, 0.735294117647, 0.609756097561, 0.5};

    auto gaussian = rbf::inverse_quadric(1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Poly-harmonic spline RBF, k=2") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0., -0.142811872841, -0.183897224556, -0.1466065171, -0.0643775164974, 0,
                               -0.0643775164974, -0.1466065171, -0.183897224556, -0.142811872841, 0.};

    auto gaussian = rbf::polyharmonic_spline(2);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Poly-harmonic spline, k=3") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {1., 0.512, 0.216, 0.064, 0.008, 0., 0.008, 0.064, 0.216, 0.512, 1.};

    auto gaussian = rbf::polyharmonic_spline(3);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Bump RBF, epsilon=0.1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0.364182191634, 0.36551746253, 0.366552688466, 0.367290362929, 0.367732259961,
                               0.367879441171, 0.367732259961, 0.367290362929, 0.366552688466, 0.36551746253,
                               0.364182191634};

    auto gaussian = rbf::bump(0.1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Bump RBF, epsilon=1") {

    using namespace std;

    vector<double> rs = {-1., -0.8, -0.6, -0.4, -0.2, 0., 0.2, 0.4, 0.6, 0.8, 1.};

    vector<double> expected = {0, 0.0621765240221, 0.209611387151, 0.304076431285, 0.352866081459, 0.367879441171,
                               0.352866081459, 0.304076431285, 0.209611387151, 0.0621765240221, 0};

    auto gaussian = rbf::bump(1);

    for (size_t i = 0; i < rs.size(); ++i) {
        CHECK(abs(gaussian(rs[i]) - expected[i]) < eps);
    }

}

TEST_CASE("Gaussian interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    DenseScalarRBFInterpolation interp(ps, v, rbf::gaussian(2.0));

    double expected = 0.563058918064;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Multi-quadric interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    DenseScalarRBFInterpolation interp(ps, v, rbf::multiquadric(2.0));

    double expected = 0.469127451265;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Inverse multi-quadric interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    DenseScalarRBFInterpolation interp(ps, v, rbf::inverse_multiquadric(2.0));

    double expected = 0.52260823968;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Inverse quadric interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    DenseScalarRBFInterpolation interp(ps, v, rbf::inverse_quadric(2.0));

    double expected = 0.535885167464;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Poly-harmonic spline, k=2") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    DenseScalarRBFInterpolation interp(ps, v, rbf::polyharmonic_spline(2));

    double expected = 0.457036122689;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Bump, epsilon=0.1") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    DenseScalarRBFInterpolation interp(ps, v, rbf::bump(0.1));

    double expected = 0.500234980288;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}
