add_library(rbf_cuda rbf_cuda_interp.cu)

target_include_directories(rbf_cuda
                           PUBLIC ${MIMG_INCLUDE_DIR})

