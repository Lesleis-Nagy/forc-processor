add_library(mimg_simple_expression
            simple_expression_driver.cpp
            simple_expression.tab.cc
            simple_expression.yy.cc)

target_include_directories(mimg_simple_expression
        PUBLIC ${MIMG_INCLUDE_DIR}
               ${CMAKE_CURRENT_SOURCE_DIR})

