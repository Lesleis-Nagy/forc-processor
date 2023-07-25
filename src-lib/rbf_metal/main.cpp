#include <iostream>

#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION

#include "Foundation/Foundation.hpp"
#include "Metal/Metal.hpp"
#include "QuartzCore/QuartzCore.hpp"

#include "rbf_metal.hpp"

template <class T>
void statistics(T *array, size_t length, T &array_mean, T &array_std);

typedef std::chrono::microseconds time_unit;
auto unit_name = "microseconds";

int main(int argc, char *argv[])
{

    // Create GPU code / arrays --------------------------------------------------------
    MTL::Device *device = MTL::CreateSystemDefaultDevice();
    MetalAdder *adder = new MetalAdder(device);

    // Verify Metal code ---------------------------------------------------------------
    adder->sendComputeCommand(); // This computes the array sum
    adder->verifyResults();

    // Profile Metal code --------------------------------------------------------------
    int repeats = 100;
    auto durations = new float[repeats];
    for (size_t repeat = 0; repeat < repeats; repeat++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        adder->sendComputeCommand();
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<time_unit>(stop - start).count();
        durations[repeat] = duration;
    }

    float array_mean;
    float array_std;
    statistics(durations, repeats, array_mean, array_std);
    std::cout << "Metal (GPU) code performance: " << std::endl;
    std::cout << array_mean << unit_name << " \t +/- " << array_std << unit_name << std::endl
              << std::endl;

    delete[] durations;
    delete adder;
    device->release();

}

template <class T>
void statistics(T *array, size_t length, T &array_mean, T &array_std)
{
    // Compute mean and standard deviation serially, template function

    array_mean = 0;
    for (size_t repeat = 0; repeat < length; repeat++)
    {
        array_mean += array[repeat];
    }
    array_mean /= length;

    array_std = 0;
    for (size_t repeat = 0; repeat < length; repeat++)
    {
        array_std += pow(array_mean - array[repeat], 2.0);
    }
    array_std /= length;
    array_std = pow(array_std, 0.5);
}
