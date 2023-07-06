add_executable(test-rbf-interpolation main.cpp)

target_include_directories(test-rbf-interpolation
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_EIGEN_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
