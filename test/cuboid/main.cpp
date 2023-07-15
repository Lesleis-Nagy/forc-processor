//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "cuboid.hpp"

using namespace mimg;

TEST_CASE("Test in_bottom_back_left()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_bottom_back_left({-.5, -.5, -.5}) == true);
    CHECK(cuboid.in_bottom_back_left({.5, -.5, -.5}) == false);
    CHECK(cuboid.in_bottom_back_left({-.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_back_left({.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_back_left({-.5, -.5, .5}) == false);
    CHECK(cuboid.in_bottom_back_left({.5, -.5, .5}) == false);
    CHECK(cuboid.in_bottom_back_left({-.5, .5, .5}) == false);
    CHECK(cuboid.in_bottom_back_left({.5, .5, .5}) == false);

}

TEST_CASE("Test in_bottom_back_right()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_bottom_back_right({-.5, -.5, -.5}) == false);
    CHECK(cuboid.in_bottom_back_right({.5, -.5, -.5}) == true);
    CHECK(cuboid.in_bottom_back_right({-.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_back_right({.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_back_right({-.5, -.5, .5}) == false);
    CHECK(cuboid.in_bottom_back_right({.5, -.5, .5}) == false);
    CHECK(cuboid.in_bottom_back_right({-.5, .5, .5}) == false);
    CHECK(cuboid.in_bottom_back_right({.5, .5, .5}) == false);

}

TEST_CASE("Test in_bottom_front_left()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_bottom_front_left({-.5, -.5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_left({.5, -.5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_left({-.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_left({.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_left({-.5, -.5, .5}) == true);
    CHECK(cuboid.in_bottom_front_left({.5, -.5, .5}) == false);
    CHECK(cuboid.in_bottom_front_left({-.5, .5, .5}) == false);
    CHECK(cuboid.in_bottom_front_left({.5, .5, .5}) == false);

}

TEST_CASE("Test in_bottom_front_right()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_bottom_front_right({-.5, -.5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_right({.5, -.5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_right({-.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_right({.5, .5, -.5}) == false);
    CHECK(cuboid.in_bottom_front_right({-.5, -.5, .5}) == false);
    CHECK(cuboid.in_bottom_front_right({.5, -.5, .5}) == true);
    CHECK(cuboid.in_bottom_front_right({-.5, .5, .5}) == false);
    CHECK(cuboid.in_bottom_front_right({.5, .5, .5}) == false);

}
TEST_CASE("Test in_top_back_left()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_top_back_left({-.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_back_left({.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_back_left({-.5, .5, -.5}) == true);
    CHECK(cuboid.in_top_back_left({.5, .5, -.5}) == false);
    CHECK(cuboid.in_top_back_left({-.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_back_left({.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_back_left({-.5, .5, .5}) == false);
    CHECK(cuboid.in_top_back_left({.5, .5, .5}) == false);

}

TEST_CASE("Test in_top_back_right()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_top_back_right({-.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_back_right({.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_back_right({-.5, .5, -.5}) == false);
    CHECK(cuboid.in_top_back_right({.5, .5, -.5}) == true);
    CHECK(cuboid.in_top_back_right({-.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_back_right({.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_back_right({-.5, .5, .5}) == false);
    CHECK(cuboid.in_top_back_right({.5, .5, .5}) == false);

}

TEST_CASE("Test in_top_front_left()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_top_front_left({-.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_front_left({.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_front_left({-.5, .5, -.5}) == false);
    CHECK(cuboid.in_top_front_left({.5, .5, -.5}) == false);
    CHECK(cuboid.in_top_front_left({-.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_front_left({.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_front_left({-.5, .5, .5}) == true);
    CHECK(cuboid.in_top_front_left({.5, .5, .5}) == false);

}

TEST_CASE("Test in_top_front_right()") {

    Cuboid cuboid({0, 0, 0}, 2, 2, 2);

    CHECK(cuboid.in_top_front_right({-.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_front_right({.5, -.5, -.5}) == false);
    CHECK(cuboid.in_top_front_right({-.5, .5, -.5}) == false);
    CHECK(cuboid.in_top_front_right({.5, .5, -.5}) == false);
    CHECK(cuboid.in_top_front_right({-.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_front_right({.5, -.5, .5}) == false);
    CHECK(cuboid.in_top_front_right({-.5, .5, .5}) == false);
    CHECK(cuboid.in_top_front_right({.5, .5, .5}) == true);

}