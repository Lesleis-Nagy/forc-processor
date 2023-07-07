include(ExternalProject)

macro (setup_antlr4)

    # Set variables.
    set(MIMG_ANTLR4 antlr-v4.12.0)
    set(MIMG_ANTLR4_DIR "${MIMG_THIRD_PARTY_DIR}/${MIMG_ANTLR4}")
    set(MIMG_ANTLR4_BUILD_DIR "${MIMG_THIRD_PARTY_BUILD_DIR}/${LIBMIO_ANTLR4}")
    set(MIMG_ANTLR4_INSTALL_DIR "${MIMG_THIRD_PARTY_INSTALL_DIR}/${LIBMIO_ANTLR4}")

    # Create required directories.
    file(MAKE_DIRECTORY ${MIMG_ANTLR4_BUILD_DIR})
    file(MAKE_DIRECTORY ${MIMG_ANTLR4_INSTALL_DIR})

    # Configure, build & install antlr4.
    execute_process(COMMAND ${CMAKE_COMMAND} ${MIMG_ANTLR4_DIR}
                                -DCMAKE_INSTALL_PREFIX=${MIMG_ANTLR4_INSTALL_DIR}
                                -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                                -DANTLR_BUILD_CPP_TESTS=OFF
                    WORKING_DIRECTORY ${MIMG_ANTLR4_BUILD_DIR})

    execute_process(COMMAND make -j 4
                    WORKING_DIRECTORY ${MIMG_ANTLR4_BUILD_DIR})

    execute_process(COMMAND make install
            WORKING_DIRECTORY ${MIMG_ANTLR4_BUILD_DIR})

    # Find headers and library.
    find_path(ANTLR4_INCLUDES
              NAMES "antlr4-common.h"
              PATHS "${MIMG_ANTLR4_INSTALL_DIR}/include/antlr4-runtime"
              NO_DEFAULT_PATH
              NO_PACKAGE_ROOT_PATH
              NO_CMAKE_PATH
              NO_CMAKE_ENVIRONMENT_PATH
              NO_SYSTEM_ENVIRONMENT_PATH
              NO_CMAKE_SYSTEM_PATH
              NO_CMAKE_INSTALL_PREFIX)

    find_library(ANTLR4_LIBRARIES "libantlr4-runtime.a"
                 PATHS "${MIMG_ANTLR4_INSTALL_DIR}/lib"
                 NO_DEFAULT_PATH
                 NO_PACKAGE_ROOT_PATH
                 NO_CMAKE_PATH
                 NO_CMAKE_ENVIRONMENT_PATH
                 NO_SYSTEM_ENVIRONMENT_PATH
                 NO_CMAKE_SYSTEM_PATH
                 NO_CMAKE_INSTALL_PREFIX)

    # Set up the antlr executable
    set(ANTLR4_EXE "${MIMG_ANTLR4_INSTALL_DIR}/antlr")
    configure_file(${CMAKE_SOURCE_DIR}/antlr.template ${ANTLR4_EXE})

    include(FindPackageHandleStandardArgs)

    find_package_handle_standard_args(ANTLR4 DEFAULT_MSG
                                      ANTLR4_INCLUDES ANTLR4_LIBRARIES)
    mark_as_advanced(ANTLR4_INCLUDES ANTLR4_LIBRARIES ANTLR4_EXE)

endmacro()
