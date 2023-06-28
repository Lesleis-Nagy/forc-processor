cmake_minimum_required(VERSION 3.25)
project(mimg)

set(CMAKE_CXX_STANDARD 20)

set(MIMG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(MIMG_SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(MIMG_THIRD_PARTY_DIR "${CMAKE_SOURCE_DIR}/third-party")
set(MIMG_TOYS_DIR "${CMAKE_SOURCE_DIR}/toys")

# Set up third-party tools that we'd like to just include.

set(MIMG_ARGS_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/args-v6.3.0/include")
set(MIMG_CATCH2_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/catch2-v2.13.9/include")
set(MIMG_RAPIDJSON_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/rapidjson-v1.1.0/include")

# Descend in to the src subdirectory.
add_subdirectory(${MIMG_SRC_DIR})

# Descend in to the toys subdirectory.
add_subdirectory(${MIMG_TOYS_DIR})
