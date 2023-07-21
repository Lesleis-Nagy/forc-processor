add_executable(cudaex main.cpp)

target_include_directories(cudaex
       PUBLIC ${MIMG_INCLUDE_DIR}
              ${CUDA_INCLUDE_DIRS})

target_link_libraries(cudaex
        rbf_cuda
        ${CUDA_LIBRARIES})
