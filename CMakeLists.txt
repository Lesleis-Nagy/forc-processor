cmake_minimum_required(VERSION 3.25)

if(WITH_CUDA)
    project(mimg LANGUAGES CXX CUDA)
else()
    project(mimg LANGUAGES CXX)
endif()

set(CMAKE_CXX_STANDARD 20)

set(MIMG_GRAMMAR_DIR "${CMAKE_SOURCE_DIR}/grammar")
set(MIMG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(MIMG_SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(MIMG_SRC_LIB_DIR "${CMAKE_SOURCE_DIR}/src-lib")
set(MIMG_TEST_DIR "${CMAKE_SOURCE_DIR}/test")
set(MIMG_THIRD_PARTY_DIR "${CMAKE_SOURCE_DIR}/third-party")
set(MIMG_TOYS_DIR "${CMAKE_SOURCE_DIR}/toys")

set(MIMG_THIRD_PARTY_BUILD_DIR "${CMAKE_BINARY_DIR}/build")
set(MIMG_THIRD_PARTY_INSTALL_DIR "${CMAKE_BINARY_DIR}/install")

# Set up third-party tools that we'd like to just include.
set(MIMG_ARGS_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/args-v6.3.0/include")
set(MIMG_CATCH2_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/catch2-v2.13.9/include")
set(MIMG_EIGEN_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/eigen-v3.4.0")
set(MIMG_METAL_CPP_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/metal-cpp")
set(MIMG_METAL_CPP_EXTENSIONS_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/metal-cpp-extensions")
set(MIMG_RAPIDJSON_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/rapidjson-v1.1.0/include")
set(MIMG_RAPIDXML_INCLUDE_DIR "${MIMG_THIRD_PARTY_DIR}/rapidxml-v1.13")

# Find packages.

#find_package(VTK REQUIRED)
find_package(HDF5 COMPONENTS CXX HL REQUIRED)
find_package(CUDA 12 REQUIRED)
message(STATUS "CUDA_LIBRARIES: ${CUDA_LIBRARIES}")
message(STATUS "CUDA_CUBLAS_LIBRARIES: ${CUDA_CUBLAS_LIBRARIES}")

if(WITH_CUDA)
    find_package(CUDA 12 REQUIRED)
endif()

# Descend

# Descend in to the src-lib subdirectory.
add_subdirectory(${MIMG_SRC_LIB_DIR})

# Descend in to the test subdirectory.
add_subdirectory(${MIMG_TEST_DIR})

# Descend in to the src subdirectory.
add_subdirectory(${MIMG_SRC_DIR})

# Descend in to the toys subdirectory.
add_subdirectory(${MIMG_TOYS_DIR})
