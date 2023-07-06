//
// Created by L. Nagy on 05/07/2023.
//

#pragma once

#include <functional>
#include <random>

#include "Point.hpp"

void eval_at_regular_points(std::vector<Point3D> &r, std::vector<double> &v,
                            double x_min, double x_max,
                            double y_min, double y_max,
                            double z_min, double z_max,
                            size_t nx, size_t ny, size_t nz,
                            const std::function<double(const Point3D& r)> &fun) {

    double dx = (x_max - x_min) / (double)(nx - 1);
    double dy = (y_max - y_min) / (double)(ny - 1);
    double dz = (z_max - z_min) / (double)(nz - 1);

    std::cout << "dx: " << dx << std::endl;
    std::cout << "dy: " << dy << std::endl;
    std::cout << "dz: " << dz << std::endl;

    r.clear();
    v.clear();

    for (size_t i = 0; i < nx; ++i) {
        for (size_t j = 0; j < ny; ++j) {
            for (size_t k = 0; k < nz; ++k) {
                double x = x_min + (double)i * dx;
                double y = y_min + (double)j * dy;
                double z = z_min + (double)k * dz;

                r.push_back({x, y, z});
                v.push_back(fun({x,y,z}));
            }
        }
    }
}

void eval_at_random_points(std::vector<Point3D> &r, std::vector<double> &v,
                           double x_min, double x_max,
                           double y_min, double y_max,
                           double z_min, double z_max,
                           size_t n,
                           const std::function<double(const Point3D& r)> &fun,
                           size_t seed=1337) {

    using std::random_device;
    using std::mt19937;
    using std::uniform_real_distribution;

    random_device device;
    mt19937 engine(device());
    engine.seed(seed);

    uniform_real_distribution<double> distr_x(x_min, x_max);
    uniform_real_distribution<double> distr_y(y_min, y_max);
    uniform_real_distribution<double> distr_z(z_min, z_max);

    r.clear();
    v.clear();

    for (size_t i = 0; i < n; ++i) {
        double x = distr_x(engine);
        double y = distr_y(engine);
        double z = distr_z(engine);

        r.push_back({x, y, z});
        v.push_back(fun({x,y,z}));
    }

}