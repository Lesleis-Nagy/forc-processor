add_executable(test-rbf main.cpp)

target_include_directories(test-rbf
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR}
               ${MIMG_INCLUDE_DIR})
