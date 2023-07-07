add_executable(ex-rapidjson-001 main.cpp ../../catch2/example-001/main.cpp)

target_include_directories(ex-rapidjson-001
        PUBLIC ${MIMG_RAPIDJSON_INCLUDE_DIR})
