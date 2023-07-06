//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN

#include <catch/catch.hpp>

#include "Rectangle.hpp"

const double eps = 1E-18;

TEST_CASE("Test in_bottom_left()") {

    Rectangle rect({0, 0}, 2, 2);

    CHECK(rect.in_bottom_left({-.5, -.5}) == true);
    CHECK(rect.in_bottom_left({.5, -.5}) == false);
    CHECK(rect.in_bottom_left({-.5, .5}) == false);
    CHECK(rect.in_bottom_left({.5, .5}) == false);

}

TEST_CASE("Test in_bottom_right()") {

    Rectangle rect({0, 0}, 2, 2);

    CHECK(rect.in_bottom_right({-.5, -.5}) == false);
    CHECK(rect.in_bottom_right({.5, -.5}) == true);
    CHECK(rect.in_bottom_right({-.5, .5}) == false);
    CHECK(rect.in_bottom_right({.5, .5}) == false);

}

TEST_CASE("Test in_top_left()") {

    Rectangle rect({0, 0}, 2, 2);

    CHECK(rect.in_top_left({-.5, -.5}) == false);
    CHECK(rect.in_top_left({.5, -.5}) == false);
    CHECK(rect.in_top_left({-.5, .5}) == true);
    CHECK(rect.in_top_left({.5, .5}) == false);

}

TEST_CASE("Test in_top_right()") {

    Rectangle rect({0, 0}, 2, 2);

    CHECK(rect.in_top_right({-.5, -.5}) == false);
    CHECK(rect.in_top_right({.5, -.5}) == false);
    CHECK(rect.in_top_right({-.5, .5}) == false);
    CHECK(rect.in_top_right({.5, .5}) == true);

}

TEST_CASE("Test bottom_left()") {
    using std::abs;

    Rectangle rect({0, 0}, 2, 2);

    Rectangle bottom_left = rect.bottom_left();

    double bottom_left_mx = -0.5;
    double bottom_left_my = -0.5;
    double bottom_left_Dx = 1.0;
    double bottom_left_Dy = 1.0;

    CHECK(abs(bottom_left.mx - bottom_left_mx) < eps);
    CHECK(abs(bottom_left.my - bottom_left_my) < eps);
    CHECK(abs(bottom_left.Dx - bottom_left_Dx) < eps);
    CHECK(abs(bottom_left.Dy - bottom_left_Dy) < eps);

}

TEST_CASE("Test bottom_right()") {
    using std::abs;

    Rectangle rect({0, 0}, 2, 2);

    Rectangle bottom_right = rect.bottom_right();

    double bottom_right_mx = 0.5;
    double bottom_right_my = -0.5;
    double bottom_right_Dx = 1.0;
    double bottom_right_Dy = 1.0;

    CHECK(abs(bottom_right.mx - bottom_right_mx) < eps);
    CHECK(abs(bottom_right.my - bottom_right_my) < eps);
    CHECK(abs(bottom_right.Dx - bottom_right_Dx) < eps);
    CHECK(abs(bottom_right.Dy - bottom_right_Dy) < eps);

}

TEST_CASE("Test top_left()") {
    using std::abs;

    Rectangle rect({0, 0}, 2, 2);

    Rectangle top_left = rect.top_left();

    double top_left_mx = -0.5;
    double top_left_my = 0.5;
    double top_left_Dx = 1.0;
    double top_left_Dy = 1.0;

    CHECK(abs(top_left.mx - top_left_mx) < eps);
    CHECK(abs(top_left.my - top_left_my) < eps);
    CHECK(abs(top_left.Dx - top_left_Dx) < eps);
    CHECK(abs(top_left.Dy - top_left_Dy) < eps);

}

TEST_CASE("Test top_right()") {
    using std::abs;

    Rectangle rect({0, 0}, 2, 2);

    Rectangle top_right = rect.top_right();

    double top_right_mx = 0.5;
    double top_right_my = 0.5;
    double top_right_Dx = 1.0;
    double top_right_Dy = 1.0;

    CHECK(abs(top_right.mx - top_right_mx) < eps);
    CHECK(abs(top_right.my - top_right_my) < eps);
    CHECK(abs(top_right.Dx - top_right_Dx) < eps);
    CHECK(abs(top_right.Dy - top_right_Dy) < eps);

}
