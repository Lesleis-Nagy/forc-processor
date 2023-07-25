//
// Created by L. Nagy on 21/07/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include <chrono>
#include <iostream>

#include "rbf_cuda_interp.hpp"

TEST_CASE("RBF CUDA") {

    int N = 10000000;

    std::vector<Real> x;
    std::vector<Real> y;
    std::vector<Real> out;

    x.reserve(N);
    y.reserve(N);
    out.reserve(N);

    std::cout << "Filling array ...\n";
    auto start_fill = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        x.push_back((Real)i);
        y.push_back(2.0);
        out.push_back(0.0);
    }
    auto stop_fill = std::chrono::high_resolution_clock::now();
    auto duration_fill = std::chrono::duration_cast<std::chrono::microseconds>(stop_fill - start_fill);
    auto size_x = sizeof(Real) * x.size();
    std::cout << "OK! (" << duration_fill.count() << " us) [" << size_x << " bytes]\n";


    cuda_saxpy(10.0, x, y, out);

    for (int i = 0; i < 100; i++) {
        std::cout << x[i] << " " << y[i] << " " << out[i] << "\n";
    }

}
