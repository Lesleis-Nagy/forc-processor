add_executable(test-rectangle main.cpp)

target_include_directories(test-rectangle
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
