//
// Created by L. Nagy on 21/07/2023.
//

#include <iostream>

#include "rbf_cuda.h"

int main(int argc, char *argv[]) {

    int N = 255;
    float *x, *y, *out;

    x = (float*)malloc(N*sizeof(float));
    y = (float*)malloc(N*sizeof(float));
    out = (float*)malloc(N*sizeof(float));

    for (int i = 0; i < N; i++) {
        x[i] = (float)i;
        y[i] = 2.0f;
        out[i] = 0.0f;
    }

    cuda_saxpy(10.0, x, y, out, N);

    for (int i = 0; i < N; i++)
        std::cout << x[i] << " " << y[i] << " " << out [i] << "\n";

    free(x);
    free(y);
    free(out);

}
