add_executable(ex-catch2-001 main.cpp ../../args/example-001/main.cpp)

target_include_directories(ex-catch2-001
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR})
