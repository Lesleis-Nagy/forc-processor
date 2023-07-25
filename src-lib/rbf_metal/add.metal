#include <metal_stdlib>
using namespace metal;

kernel void add_arrays(device const float *in_a,
                       device const float *in_b,
                       device       float *result,
                       uint                index[[thread_position_in_grid]]) {

    result[index] = in_a[index] + in_b[index];

}