add_executable(test-fraction main.cpp)

target_include_directories(test-fraction
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
