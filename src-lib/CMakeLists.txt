add_subdirectory(simple_expression)

if(WITH_CUDA)
    add_subdirectory(rbf_cuda)
endif()

if (WITH_METAL)
    add_subdirectory(rbf_metal)
endif()
