add_executable(rbftool main.cpp)

target_include_directories(rbftool
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_EIGEN_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
