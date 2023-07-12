//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include "simple_expression.hpp"

const double eps = 1E-18;

TEST_CASE("Test in_bottom_left()") {

    SimpleExpression se;

    SimpleScalarCalculator calculator = se.parse("23.3*sin(x*(y+z))");

    std::cout << "23.3*sin(2*(3+4)) = " << calculator(2,3,4) << std::endl;
    std::cout << "23.3*sin(4*(2+3)) = " << calculator(4,2,3) << std::endl;

}
