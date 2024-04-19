cmake_minimum_required(VERSION 3.10)
project(ATMsim)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main application executable
add_executable(ATMsim main.cpp AccountHolder/AccountHolder.cpp CheckingSaving/CheckingSaving.cpp Program_Flow/program_flow.cpp)

# Specify include directories for the main executable
target_include_directories(ATMsim PRIVATE ${CMAKE_SOURCE_DIR}/AccountHolder ${CMAKE_SOURCE_DIR}/CheckingSaving ${CMAKE_SOURCE_DIR}/Program_Flow)

# Setup for GoogleTest
find_package(GTest REQUIRED)  # This locates the GoogleTest library

# Add the test executable
add_executable(test_account AccountHolder/AccountHolder_test.cpp)
# Link Google Test to the test executable
target_link_libraries(test_account GTest::GTest GTest::Main)