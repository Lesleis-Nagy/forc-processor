add_executable(test-rbf-cuda-interp main.cpp)

target_include_directories(test-rbf-cuda-interp
       PUBLIC ${MIMG_INCLUDE_DIR}
              ${MIMG_CATCH2_INCLUDE_DIR}
              ${CUDA_INCLUDE_DIRS})

target_link_libraries(test-rbf-cuda-interp
        rbf_cuda
        ${CUDA_LIBRARIES})
