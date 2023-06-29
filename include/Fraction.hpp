//
// Created by L. Nagy on 28/06/2023.
//

#pragma once

#include <iostream>
#include <string>
#include <sstream>

template <typename T> long sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

template <class T>
inline void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

class Fraction {

public:

    Fraction(): _n(0), _d(1) {}

    Fraction(long n, long d): _n(n), _d(d) {}

    Fraction(int n, int d): _n(n), _d(d) {}

    explicit Fraction(double v, long max_precision=4):_n(0), _d(1) {
        set(v, max_precision);
    }

    explicit Fraction(const char *v, long max_precision=4):_n(0), _d(1) {
        set(std::stod(v), max_precision);
    }

    explicit Fraction(const std::string &v, long max_precision=4): _n(0), _d(1) {
        set(std::stod(v), max_precision);
    }

    [[nodiscard]] long numerator() const {
        return _n;
    }

    [[nodiscard]] long denominator() const {
        return _d;
    }

    [[nodiscard]] Fraction inverse() const {
        return {_d, _n};
    }

    [[nodiscard]] Fraction operator+ (const Fraction &rhs) const {
        auto n = _n * rhs.denominator() + _d * rhs.numerator();
        if (n == 0) {
            return {0, 1};
        }
        auto d = _d * rhs.denominator();
        auto g = gcd(n, d);
        return {n/g, d/g};
    }

    [[nodiscard]] Fraction operator- (const Fraction &rhs) const {
        auto n = _n * rhs.denominator() - _d * rhs.numerator();
        if (n == 0) {
            return {0, 1};
        }
        auto d = _d * rhs.denominator();
        auto g = gcd(n, d);
        return {n/g, d/g};
    }

    [[nodiscard]] Fraction operator* (const Fraction &rhs) const {
        auto n = _n * rhs.numerator();
        if (n == 0) {
            return {0, 1};
        }
        auto d = _d * rhs.denominator();
        auto g = gcd(n, d);
        return {n/g, d/g};
    }

    [[nodiscard]] Fraction operator/(const Fraction &rhs) const {
        auto n = _n * rhs.denominator();
        if (n == 0) {
            return {0, 1};
        }
        auto d = _d * rhs.numerator();
        auto g = gcd(n, d);
        return {n/g, d/g};
    }

    [[nodiscard]] bool operator ==(const Fraction &rhs) const {
        return _n * rhs.denominator() == _d * rhs.numerator();
    }

    [[nodiscard]] double as_double() const {
        return (double)_n / (double)_d;
    }

private:

    [[nodiscard]] long gcd(long n1, long n2) const {

        n1 = ( n1 > 0) ? n1 : -n1;
        n2 = ( n2 > 0) ? n2 : -n2;

        while(n1!=n2)
        {
            if(n1 > n2)
                n1 -= n2;
            else
                n2 -= n1;
        }

        return n1;
    }


    void set(double v, long max_precision) {

        // The sign of the number.
        long sign = sgn(v);

        // Make sure the number is positive.
        double vpos = v < 0.0 ? -1.0 * v : v;

        // Isolate the fraction part of the number.
        double frac_part = vpos - (long) vpos;

        // Isolate the integer part of the number.
        long int_part = (long) vpos;

        // used to 'pop' digits off the frac_part.
        double dbl_power = 10.0;

        // denominator of the fraction part.
        long denominator = 10;
        for (long i = 1; i <= max_precision; ++i) {
            denominator *= 10;
        }

        // used to rebuild digits of the frac_part in to numerator.
        long int_power = denominator / 10;

        // numerator of the fraction part (accumulated in the for loop).
        long numerator = 0;

        for (long digit_idx = 1; digit_idx <= max_precision; ++digit_idx) {

            // Shift frac_part up by a digit and grab that digit.
            auto digit = (long) (frac_part * dbl_power);

            // Remove the digit from frac_part.
            frac_part = frac_part * dbl_power - (double) digit;

            // Accumulate the digit in to numerator.
            numerator += digit * int_power;

            // Shift to the right by a digit.
            int_power /= 10;

        }

        if (numerator == 0) {

            _n = 0;
            _d = 1;

        } else {

            auto g1 = gcd(numerator, denominator);

            numerator /= g1;
            denominator /= g1;

            numerator = numerator + int_part * denominator;

            auto g2 = gcd(numerator, denominator);

            numerator /= g2;
            denominator /= g2;

            _n = sign * numerator;
            _d = denominator;

        }
    }


    long _n;
    long _d;

};

template<>
struct std::hash<Fraction>
{
    std::size_t operator()(Fraction const& v) const noexcept
    {
        std::size_t n = std::hash<long>{}(v.numerator());
        std::size_t d = std::hash<long>{}(v.denominator());

        size_t seed = 0;

        hash_combine(seed, n);
        hash_combine(seed, d);

        return seed;
    }
};


std::ostream & operator<<(std::ostream & out, Fraction fp) {
    out << fp.numerator() << "/" << fp.denominator();
    return out;
}