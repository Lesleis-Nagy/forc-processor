add_executable(fmtec2hdf5 main.cpp)

target_include_directories(fmtec2hdf5
    PUBLIC ${MIMG_INCLUDE_DIR}
           ${MIMG_ARGS_INCLUDE_DIR}
           ${MIMG_RAPIDXML_INCLUDE_DIR}
           ${HDF5_INCLUDE_DIRS})

target_link_libraries(fmtec2hdf5
        ${HDF5_LIBRARIES}
        ${HDF5_HL_LIBRARIES})
