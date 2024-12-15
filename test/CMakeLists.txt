include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/35d0c365609296fa4730d62057c487e3cfa030ff.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(6502_cpp_tests 6502_cpp_alu.cpp)

target_link_libraries(6502_cpp_tests PRIVATE 6502_cpp_core gtest_main)

target_include_directories(6502_cpp_tests PRIVATE ../src)

# find tests
include(GoogleTest)
gtest_discover_tests(6502_cpp_tests PROPERTIES LABELS "unit" DISCOVERY_TIMEOUT 240)
