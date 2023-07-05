add_executable(test-cuboid main.cpp)

target_include_directories(test-cuboid
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
        ${MIMG_INCLUDE_DIR})