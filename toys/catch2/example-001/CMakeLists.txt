add_executable(catch2-ex-001 main.cpp ../../args/example-001/main.cpp)

target_include_directories(catch2-ex-001
        PUBLIC ${MIMG_CATCH2_INCLUDE_DIR})