//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <sstream>

#include "simple_expression_driver.hpp"

const double eps = 1E-18;

TEST_CASE("Test in_bottom_left()") {

    using std::vector;
    using std::stringstream;

    using mimg::SimpleExpressionDriver;

    SimpleExpressionDriver driver;


    stringstream ss;
    ss << "This is one\nAnd this is two.";

    driver.parse(ss);

    std::cout << driver << std::endl;

}

