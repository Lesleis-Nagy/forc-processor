//
// Created by L. Nagy on 21/07/2023.
//

#include "rbf_cuda.h"

__global__
void saxpy(float a, float *x, float *y) {

    int i = blockIdx.x*blockDim.x + threadIdx.x;
    y[i] = a*x[i] + y[i];

}

void cuda_saxpy(float a, float *in_x, float *in_y, float *out_x, int n) {

    float *d_x, *d_y;

    // Allocate memory on CUDA device.
    cudaMalloc(&d_x, n*sizeof(float));
    cudaMalloc(&d_y, n*sizeof(float));

    // Copy x and y arrays to device.
    cudaMemcpy(d_x, in_x, n*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, in_y, n*sizeof(float), cudaMemcpyHostToDevice);

    // Perform SAXPY on 1M elements
    saxpy<<<1, n>>>(a, d_x, d_y);

    cudaMemcpy(out_x, d_y, n*sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(d_x);
    cudaFree(d_y);

}
