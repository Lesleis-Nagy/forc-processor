//
// Created by L. Nagy on 21/07/2023.
//

#include "rbf_cuda.hpp"

__global__
void saxpy(float a, float *x, float *y) {

    int i = blockIdx.x*blockDim.x + threadIdx.x;
    y[i] = a*x[i] + y[i];

}

void cuda_saxpy(float a,
                const std::vector<float> &in_x,
                const std::vector<float> &in_y,
                std::vector<float> &out) {

    float *d_x, *d_y;

    // Allocate memory on CUDA device.
    cudaMalloc(&d_x, in_x.size()*sizeof(float));
    cudaMalloc(&d_y, in_y.size()*sizeof(float));

    // Copy x and y arrays to device.
    cudaMemcpy(d_x, in_x.data(), in_x.size()*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, in_y.data(), in_y.size()*sizeof(float), cudaMemcpyHostToDevice);

    out.resize(in_x.size());

    // Perform SAXPY on 1M elements
    saxpy<<<1, out.size()>>>(a, d_x, d_y);

    cudaMemcpy(out.data(), d_y, out.size() * sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(d_x);
    cudaFree(d_y);

}
