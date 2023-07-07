//
// Created by L. Nagy on 05/07/2023.
//

#include "point_populator.hpp"
#include "rbf_interpolation.hpp"

#define M_PI 3.14159265358979323846


int main(int argc, char *argv[]) {

    std::function<double(const Point3D &)> test_fun = [](const Point3D &r) {
        return std::exp(std::sin(r.x) + std::cos(r.y) - r.z);
    };

    std::vector<Point3D> ipts;
    std::vector<double> ivals;
    eval_at_regular_points(ipts, ivals, -M_PI, M_PI, -M_PI, M_PI, -M_PI, M_PI, 10, 10, 10, test_fun);

    std::vector<Point3D> tpts;
    std::vector<double> tvals;
    eval_at_regular_points(tpts, tvals, -M_PI, M_PI, -M_PI, M_PI, -M_PI, M_PI, 100, 100, 100, test_fun);

    DenseScalarRBFInterpolation interp(ipts, ivals, rbf::multiquadric(3.0));

    std::vector<Point3D> apts;
    std::vector<double> avals;
    eval_at_regular_points(apts, avals, -M_PI, M_PI, -M_PI, M_PI, -M_PI, M_PI, 100, 100, 100, interp);

    std::cout << "tpts.size() = " << tpts.size() << std::endl;
    std::cout << "tvals.size() = " << tvals.size() << std::endl;
    std::cout << "avals.size() = " << avals.size() << std::endl;

    for (size_t i = 0; i < tpts.size(); ++i) {
        std::cout << tpts[i] << "(" << apts[i] << ")" << " " << tvals[i] << " " << avals[i] << "\n";
    }

    return 0;

}
