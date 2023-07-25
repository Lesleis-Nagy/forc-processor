
add_custom_target(rbf_metal_kernel
        COMMAND xcrun -sdk macosx metal -c add.metal -o ${CMAKE_CURRENT_BINARY_DIR}/MyLibrary.air
        COMMAND xcrun -sdk macosx metallib ${CMAKE_CURRENT_BINARY_DIR}/MyLibrary.air -o ${CMAKE_CURRENT_BINARY_DIR}/default.metallib
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        SOURCES add.metal)

add_executable(rbf_metal_exe main.cpp)

target_include_directories(rbf_metal_exe
                           PUBLIC ${MIMG_INCLUDE_DIR}
                                   ${MIMG_METAL_CPP_INCLUDE_DIR})

target_link_libraries(rbf_metal_exe
                      rbf_metal_lib)

target_link_libraries(rbf_metal_exe
        "-framework Metal"
        "-framework MetalKit"
        "-framework AppKit"
        "-framework Foundation"
        "-framework QuartzCore")

add_dependencies(rbf_metal_exe rbf_metal_kernel)

add_library(rbf_metal_lib rbf_metal.cpp)

target_include_directories(rbf_metal_lib
                           PUBLIC ${MIMG_INCLUDE_DIR}
                                  ${MIMG_METAL_CPP_INCLUDE_DIR})
