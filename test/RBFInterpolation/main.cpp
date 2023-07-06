//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "PointEvaluation.hpp"
#include "RBFInterpolation.hpp"

#define M_PI 3.14159265358979323846



TEST_CASE("Upscale interpolation - regular grid to higher resolution regular grid") {

    std::function<double(const Point3D &)> test_fun = [](const Point3D &r) {
        return std::exp(std::sin(r.x) + std::cos(r.y) - r.z);
    };

    std::vector<Point3D> ipts;
    std::vector<double> ivals;
    eval_at_regular_points(ipts, ivals, -M_PI, M_PI, -M_PI, M_PI, -M_PI, M_PI, 10, 10, 10, test_fun);

    std::vector<Point3D> epts;
    std::vector<double> evals;
    eval_at_regular_points(epts, evals, -M_PI, M_PI, -M_PI, M_PI, -M_PI, M_PI, 100, 100, 100, test_fun);

    DenseScalarRBFInterpolation interp(ipts, ivals, RBFFactory::multiquadric(3.0));

    std::vector<Point3D> apts;
    std::vector<double> avals;
    eval_at_regular_points(apts, avals, -M_PI, M_PI, -M_PI, M_PI, -M_PI, M_PI, 100, 100, 100, interp);


    double error = 0.0;
    for (size_t i = 0; i < epts.size(); ++i) {
        double lcl_error = (evals[i] - avals[i]) * (evals[i] - avals[i]);
        error += lcl_error;
    }
    error = std::sqrt(error / (double)epts.size());

    std::cout << "Error: " << error << std::endl;
    std::cout << "Expected: " << test_fun({1,2,1}) << std::endl;
    std::cout << "Interpolated: " << interp({1,2,1}) << std::endl;


}

