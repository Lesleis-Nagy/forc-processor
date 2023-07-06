add_executable(rbf main.cpp)

target_include_directories(rbf
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_EIGEN_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
