add_executable(test-fixed-point main.cpp)

target_include_directories(test-fixed-point
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
