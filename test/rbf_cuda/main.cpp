//
// Created by L. Nagy on 21/07/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include <iostream>

#include "rbf_cuda.hpp"

TEST_CASE("RBF CUDA") {

    int N = 255;

    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> out;

    x.reserve(N);
    y.reserve(N);
    out.reserve(N);

    for (int i = 0; i < N; i++) {
        x.push_back((float)i);
        y.push_back(2.0);
        out.push_back(0.0);
    }

    cuda_saxpy(10.0, x, y, out);

    for (int i = 0; i < N; i++) {
        std::cout << x[i] << " " << y[i] << " " << out [i] << "\n";
    }

}
