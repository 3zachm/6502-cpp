cmake_minimum_required(VERSION 3.30)
project(6502_cpp)

set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

find_program(GCOV_PATH gcov)
if (NOT GCOV_PATH)
    message(FATAL_ERROR "Code coverage analysis requires gcov")
endif ()

add_subdirectory(src)

option(6502_CPP_TESTS "Build unit tests" ON)

if(6502_CPP_TESTS)
    enable_testing()
    add_subdirectory("test")
endif()
