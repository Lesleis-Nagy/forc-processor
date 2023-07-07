//
// Created by L. Nagy on 27/06/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "fraction.hpp"


TEST_CASE("Test normal operation", "part 1") {

    Fraction fpp(100.123);
    Fraction fpn(-100.123);
    Fraction fpp2(100.123456789);

    Fraction fp3 = fpp + fpn;

    std::cout << fpp << std::endl;
    std::cout << fpn << std::endl;
    std::cout << fpp2 << std::endl;
    std::cout << fp3 << std::endl;

}

