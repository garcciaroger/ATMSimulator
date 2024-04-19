cmake_minimum_required(VERSION 3.10)

# Set the main project name
project(ATMsim)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Ensure -std=c++17 is added to the compile commands

# Add the main application executable
add_executable(ATMsim main.cpp AccountHolder/AccountHolder.cpp CheckingSaving/CheckingSaving.cpp)  # Adjust paths as necessary

# Setup for GoogleTest
find_package(GTest REQUIRED)  # This locates the GoogleTest library

# Add the test executable
add_executable(test_account AccountHolder/AccountHolder_test.cpp)

# Link Google Test to the test executable
target_link_libraries(test_account GTest::GTest GTest::Main)

