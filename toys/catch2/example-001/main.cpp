//
// Created by L. Nagy on 27/06/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>


TEST_CASE("Some test", "part 1") {

    int expected_value = 1;
    int actual_value = 1;

    REQUIRE(expected_value == actual_value);

}