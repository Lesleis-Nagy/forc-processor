//
// Created by L. Nagy on 21/07/2023.
//

#pragma once

#include <vector>

#include <cuda_runtime_api.h>
#include <cuda.h>

__global__
void saxpy(float a, float *x, float *y);

void cuda_saxpy(float a,
                const std::vector<float> &in_x,
                const std::vector<float> &in_y,
                std::vector<float> &out);