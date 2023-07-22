add_executable(test-rbf-cuda main.cpp)

target_include_directories(test-rbf-cuda
       PUBLIC ${MIMG_INCLUDE_DIR}
              ${MIMG_CATCH2_INCLUDE_DIR}
              ${CUDA_INCLUDE_DIRS})

target_link_libraries(test-rbf-cuda
        rbf_cuda
        ${CUDA_LIBRARIES})
