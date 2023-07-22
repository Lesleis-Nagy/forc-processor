//
// Created by L. Nagy on 21/07/2023.
//

#include <chrono>
#include <iostream>


#include "rbf_cuda_interp.hpp"

__global__
void saxpy(Real a, const Real *x, Real *y) {

    size_t i = blockIdx.x*blockDim.x + threadIdx.x;
    y[i] = a*x[i] + y[i];

}

void cuda_saxpy(Real a,
                const std::vector<Real> &in_x,
                const std::vector<Real> &in_y,
                std::vector<Real> &out) {

    Real *d_x, *d_y;

    size_t threadsPerBlock = 256;
    size_t blocksPerGrid = (in_x.size() + threadsPerBlock - 1) / threadsPerBlock;

    // Allocate memory on CUDA device.
    std::cout << "Allocating memory on device ...\n";
    auto start_cudaMalloc = std::chrono::high_resolution_clock::now();
    cudaMalloc(&d_x, in_x.size()*sizeof(Real));
    cudaMalloc(&d_y, in_y.size()*sizeof(Real));
    auto stop_cudaMalloc = std::chrono::high_resolution_clock::now();
    auto duration_cudaMalloc = std::chrono::duration_cast<std::chrono::microseconds>(stop_cudaMalloc - start_cudaMalloc);
    std::cout << "OK! (" << duration_cudaMalloc.count() << " us)\n";

    // Copy x and y arrays to device.
    std::cout << "Copying memory to device ...\n";
    auto start_cudaMemcpy1 = std::chrono::high_resolution_clock::now();
    cudaMemcpy(d_x, in_x.data(), in_x.size()*sizeof(Real), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, in_y.data(), in_y.size()*sizeof(Real), cudaMemcpyHostToDevice);
    auto stop_cudaMemcpy1 = std::chrono::high_resolution_clock::now();
    auto duration_cudaMemcpy1 = std::chrono::duration_cast<std::chrono::microseconds>(stop_cudaMemcpy1 - start_cudaMemcpy1);
    std::cout << "OK! (" << duration_cudaMemcpy1.count() << " us)\n";

    out.resize(in_x.size());

    // Perform SAXPY.
    std::cout << "Running saxpy kernel ...\n";
    auto start_saxpy = std::chrono::high_resolution_clock::now();
    saxpy<<<blocksPerGrid, threadsPerBlock>>>(a, d_x, d_y);
    auto stop_saxpy = std::chrono::high_resolution_clock::now();
    auto duration_saxpy = std::chrono::duration_cast<std::chrono::microseconds>(stop_saxpy - start_saxpy);
    std::cout << "OK! (" << duration_saxpy.count() << " us)\n";

    std::cout << "Copying memory to CPU ...\n";
    auto start_cudaMemcpy2 = std::chrono::high_resolution_clock::now();
    cudaMemcpy(out.data(), d_y, out.size() * sizeof(Real), cudaMemcpyDeviceToHost);
    auto stop_cudaMemcpy2 = std::chrono::high_resolution_clock::now();
    auto duration_cudaMemcpy2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_cudaMemcpy2 - start_cudaMemcpy2);
    std::cout << "OK! (" << duration_cudaMemcpy2.count() << " us)\n";

    cudaFree(d_x);
    cudaFree(d_y);

}
