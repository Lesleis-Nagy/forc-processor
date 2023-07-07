add_executable(test-simple-expression main.cpp)

target_include_directories(test-simple-expression
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})

target_link_libraries(test-simple-expression
        mimg_simple_expression)
