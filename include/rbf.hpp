//
// Created by L. Nagy on 07/07/2023.
//

#pragma once

#include <cmath>

#include <functional>

namespace mimg {

    class rbf {

    public:

        rbf() = default;

        static std::function<double(double)> gaussian(double epsilon) {
            using std::exp;

            return [epsilon](double r) {
                return exp(-1.0 * epsilon * epsilon * r * r);
            };
        }

        static std::function<double(double)> multiquadric(double epsilon) {
            using std::sqrt;

            return [epsilon](double r) {
                return sqrt(1 + epsilon * epsilon * r * r);
            };
        }

        static std::function<double(double)> inverse_quadric(double epsilon) {
            return [epsilon](double r) {
                return 1.0 / (1 + epsilon * epsilon * r * r);
            };
        }

        static std::function<double(double)> inverse_multiquadric(double epsilon) {
            using std::sqrt;

            return [epsilon](double r) {
                return 1.0 / sqrt(1 + epsilon * epsilon * r * r);
            };
        }

        static std::function<double(double)> polyharmonic_spline(size_t k) {
            using std::abs;
            using std::log;
            using std::pow;

            if (k % 2 == 0) {
                return [k](double r) {
                    if (abs(r) > 0.0) {
                        return pow(abs(r), (double) k) * log(abs(r));
                    } else {
                        return 0.0;
                    }
                };
            } else {
                return [k](double r) {
                    return pow(abs(r), (double) k);
                };
            }
        }

        static std::function<double(double)> thin_plate_spline() {
            using std::log;

            return [](double r) {
                if (r > 0.0) {
                    return r * r * log(r);
                } else {
                    return 0.0;
                }
            };
        }

        static std::function<double(double)> bump(double epsilon) {
            using std::exp;
            using std::abs;

            return [epsilon](double r) {
                if (std::abs(r) < (1.0 / epsilon)) {
                    return std::exp(1.0 / (epsilon * epsilon * r * r - 1));
                } else {
                    return 0.0;
                }
            };
        }

    };

} // namespace mimg