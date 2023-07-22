//
// Created by L. Nagy on 21/07/2023.
//

#pragma once

#include <vector>

#include <cuda_runtime_api.h>
#include <cuda.h>

typedef float Real;

__global__
void saxpy(Real a, const Real *x, Real *y);

void cuda_saxpy(Real a,
                const std::vector<Real> &in_x,
                const std::vector<Real> &in_y,
                std::vector<Real> &out);
