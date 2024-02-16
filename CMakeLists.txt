cmake_minimum_required(VERSION 3.14)
project(lnums)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable code coverage flags
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

# Include "gtest" library
include(FetchContent)
FetchContent_Declare(
 googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)


# Include "LongNums" and "CalcPi" libraries
add_library(LongNums libs/LongNums/LongNums.cpp)
add_library(CalcPi libs/CalcPi/CalcPi.cpp)

# Link libraries to main.cpp
add_executable(main_file main.cpp)
target_link_libraries(main_file LongNums CalcPi)
target_include_directories(main_file PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/LongNums"
                          "${PROJECT_SOURCE_DIR}/libs/CalcPi"
)

# Link libraries to test.cpp
add_executable(test_file test/test.cpp)
target_link_libraries(test_file LongNums CalcPi GTest::gtest_main)
target_include_directories(test_file PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/LongNums"
                          "${PROJECT_SOURCE_DIR}/libs/CalcPi"
)
gtest_discover_tests(test_file)