//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "point_populator.hpp"
#include "rbf_dscal_interp.hpp"

using namespace mimg;

const double eps = 1e-10;

TEST_CASE("Gaussian interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    RBFDenseScalarInterpolation interp(ps, v, rbf::gaussian(2.0));

    double expected = 0.563058918064;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Multi-quadric interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    RBFDenseScalarInterpolation interp(ps, v, rbf::multiquadric(2.0));

    double expected = 0.469127451265;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Inverse multi-quadric interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    RBFDenseScalarInterpolation interp(ps, v, rbf::inverse_multiquadric(2.0));

    double expected = 0.52260823968;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Inverse quadric interpolation, epsilon=2.0") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    RBFDenseScalarInterpolation interp(ps, v, rbf::inverse_quadric(2.0));

    double expected = 0.535885167464;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Poly-harmonic spline, k=2") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    RBFDenseScalarInterpolation interp(ps, v, rbf::polyharmonic_spline(2));

    double expected = 0.457036122689;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}

TEST_CASE("Bump, epsilon=0.1") {

    using namespace std;

    vector<Point3D> ps = {{0.5,  0.5,  0.5}, {0.75, 0.75, 0.75}};

    vector<double> v = {0.0, 1.0};

    RBFDenseScalarInterpolation interp(ps, v, rbf::bump(0.1));

    double expected = 0.500234980288;

    CHECK(abs(interp({0.5, 0.5, 0.5}) - 0.0) < eps);
    CHECK(abs(interp({0.625, 0.625, 0.625}) - expected) < eps);
    CHECK(abs(interp({0.75, 0.75, 0.75}) - 1.0) < eps);

}
