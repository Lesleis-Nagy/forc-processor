//
// Created by L. Nagy on 21/07/2023.
//

#pragma once

#include <cuda_runtime_api.h>
#include <cuda.h>

__global__
void saxpy(float a, float *x, float *y);

extern "C" void cuda_saxpy(float a, float *in_x, float *in_y, float *out_x, int n);
