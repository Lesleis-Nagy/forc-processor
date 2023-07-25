add_executable(test-rbf-cpu-interp main.cpp)

target_include_directories(test-rbf-cpu-interp
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_EIGEN_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
