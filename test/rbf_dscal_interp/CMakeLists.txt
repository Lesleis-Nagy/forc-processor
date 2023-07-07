add_executable(test-rbf-dscal-interp main.cpp)

target_include_directories(test-rbf-dscal-interp
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_EIGEN_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
