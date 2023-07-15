//
// Created by L. Nagy on 27/06/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "fraction.hpp"


TEST_CASE("Test with double - 1") {

    Fraction fpp(100.123);

    CHECK(fpp.numerator() == 100123);
    CHECK(fpp.denominator() == 1000);

}

TEST_CASE("Test with double - 2") {

    Fraction fpp(100e-3);

    CHECK(fpp.numerator() == 1);
    CHECK(fpp.denominator() == 10);

}

TEST_CASE("Test with double - 3") {

    Fraction fpp(1.123456e-3);

    CHECK(fpp.numerator() == 11);
    CHECK(fpp.denominator() == 10000);

}

TEST_CASE("Test with string - 1") {

    Fraction fpp("100.123");

    CHECK(fpp.numerator() == 100123);
    CHECK(fpp.denominator() == 1000);

}

TEST_CASE("Test with string - 2") {

    Fraction fpp("100e-3");

    CHECK(fpp.numerator() == 1);
    CHECK(fpp.denominator() == 10);

}

TEST_CASE("Test with string - 3") {

    Fraction fpp("1.123456e-3");

    CHECK(fpp.numerator() == 11);
    CHECK(fpp.denominator() == 10000);

}
