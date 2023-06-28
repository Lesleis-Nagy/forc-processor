//
// Created by L. Nagy on 28/06/2023.
//

#pragma once

#include <iostream>
#include <string>

class FixedPoint {

public:

    FixedPoint() = default;

    FixedPoint(const FixedPoint &rhs) = default;

    FixedPoint &operator= (const FixedPoint &rhs) = default;

    explicit FixedPoint(const char *rhs) {
        double v = std::stod(rhs);
        _value = (long long)(v * 4294967296); // shift right by 2^32 bits (4 bytes).
    }

    FixedPoint &operator= (const char *rhs) {
        double v = std::stod(rhs);
        _value = (long long)(v * 4294967296); // shift right by 2^32 bits (4 bytes).
        return *this;
    }

    explicit FixedPoint(const std::string &rhs) {
        double v = std::stod(rhs);
        _value = (long long)(v * 4294967296); // shift right by 2^32 bits (4 bytes).
    }

    FixedPoint &operator= (const std::string &rhs) {
        double v = std::stod(rhs);
        _value = (long long)(v * 4294967296); // shift right by 2^32 bits (4 bytes).
        return *this;
    }

    explicit FixedPoint(double rhs) {
        _value = (long long)(rhs * 4294967296); // shift right by 2^32 bits (4 bytes).
    }

    FixedPoint &operator= (double rhs) {
        _value = (long long)(rhs * 4294967296); // shift right by 2^32 bits (4 bytes).
        return *this;
    }

    [[nodiscard]] long long int_part() const {
        return _value >> 32;
    }

    [[nodiscard]] long long frac_part() const {
        return _value & 0xFFFFFFFF;
    }

    [[nodiscard]] long long value() const {
        return _value;
    }


private:
    long long _value;

};

std::ostream & operator<<(std::ostream & out, FixedPoint fp) {
    out << fp.int_part() << "." << fp.frac_part() << " (" << std::hex << fp.value() << ")";
    return out;
}