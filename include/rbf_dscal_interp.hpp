//
// Created by L. Nagy on 05/07/2023.
//

#pragma once

#include <utility>
#include <vector>

#include <Eigen/Dense>

#include "point.hpp"
#include "rbf.hpp"


template <typename PointND>
class RBFDenseScalarInterpolation {
public:

    RBFDenseScalarInterpolation(const std::vector<PointND> &r,
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

    double operator() (const PointND &reval) const {

        using Eigen::Index;

        double result = 0.0;
        for (Index i = 0; i < _w.size(); ++i) {
            result += _rbf(distance(_r[i], reval)) * _w(i);
        }

        return result;
    }

private:

    std::function<double(double)> _rbf;
    std::vector<PointND> _r;
    Eigen::VectorXd _w;

};
