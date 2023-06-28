//
// Created by L. Nagy on 27/06/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "FixedPoint.hpp"


TEST_CASE("Some test", "part 1") {

    FixedPoint fp(100.123);

    std::cout << fp << std::endl;

    // REQUIRE(expected_value == actual_value);

}