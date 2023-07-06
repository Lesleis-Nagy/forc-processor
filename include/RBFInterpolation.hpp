//
// Created by L. Nagy on 05/07/2023.
//

#pragma once

#include <cmath>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include "Point.hpp"


class RBFFactory {

public:

    RBFFactory() = default;

    static std::function<double(double)> gaussian(double epsilon = 1E-5) {
        return [epsilon](double r) {
            return std::exp(-1.0 * epsilon * epsilon * r * r);
        };
    }

    static std::function<double(double)> multiquadric(double epsilon = 1E-5) {
        return [epsilon](double r) {
            return std::sqrt(1 + epsilon * epsilon * r * r);
        };
    }

    static std::function<double(double)> inverse_quadric(double epsilon = -1E-5) {
        return [epsilon](double r) {
            return 1.0 / (1 + epsilon * epsilon * r * r);
        };
    }

    static std::function<double(double)> inverse_multiquadric(double epsilon = -1E-5) {
        return [epsilon](double r) {
            return 1.0 / std::sqrt(1 + epsilon * epsilon * r * r);
        };
    }

    static std::function<double(double)> polyharmonic_spline(size_t k = 3) {
        if (k % 2 == 0) {
            return [k](double r) {
                return std::pow(r, double(k)) * std::log(r);
            };
        } else {
            return [k](double r) {
                return std::pow(r, (double) k);
            };
        }
    }

    static std::function<double(double)> thin_plate_spline(double epsilon = -1E-5) {
        return [epsilon](double r) {
            return r * r * std::log(r);
        };
    }

    static std::function<double(double)> bump_function(double epsilon = -1E-5) {
        return [epsilon](double r) {
            if (r < 1.0 / epsilon) {
                return std::exp(1.0 / (epsilon * epsilon * r * r - 1));
            } else {
                return 0.0;
            }
        };
    }

};

class DenseScalarRBFInterpolation {
public:

    DenseScalarRBFInterpolation(const std::vector<Point3D> &r,
                                const std::vector<double> &v,
                                std::function<double(double)> rbf) : _rbf(std::move(rbf)) {

        using Eigen::MatrixXd;
        using Eigen::VectorXd;
        using Eigen::Index;

        // Solve the system Aw = f, for w.
        MatrixXd A(v.size(), v.size());
        VectorXd f(v.size());

        for (Index i = 0; i < v.size(); ++i) {
            for (Index j = 0; j < v.size(); ++j) {
                A(i,j) = _rbf(distance(r[i], r[j]));
            }
            f(i) = v[i];
        }

        _w = A.partialPivLu().solve(f);
        _r = r;

    }

    double operator() (const Point3D &reval) const {

        using Eigen::Index;

        double result = 0.0;
        for (Index i = 0; i < _w.size(); ++i) {
            result += _rbf(distance(_r[i], reval)) * _w(i);
        }

        return result;
    }

private:

    std::function<double(double)> _rbf;
    std::vector<Point3D> _r;
    Eigen::VectorXd _w;

};
