add_library(6502_cpp_core memory.cpp)

target_include_directories(6502_cpp_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(6502_cpp main.cpp)

target_link_libraries(6502_cpp PRIVATE 6502_cpp_core)
