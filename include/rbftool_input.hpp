//
// Created by Lesleis Nagy on 09/07/2023.
//

#pragma once

#include <optional>
#include <tuple>
#include <exception>

namespace mimg {

    class DoubleRange {

    public:

        DoubleRange(double start, double end, size_t n) :
                _start(start), _end(end), _n(n) {}

    private:

        double _start;
        double _end;
        size_t _n;

    };

    class RBFToolInput {
    public:

        enum FieldType {
            SCALAR2D, VECTOR2D,
            SCALAR3D, VECTOR3D
        };

        enum PointType {
            UNIFORM, RANDOM
        };

        enum InterpolationType {
            GAUSSIAN
        };

    private:

    };

} // namespace mimg
