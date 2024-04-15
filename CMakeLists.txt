cmake_minimum_required(VERSION 3.25)
project(ATMSimulator)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Main application executable
add_executable(ATMSimulator
        main.cpp
        AccountHolder/AccountHolder.cpp
        AccountHolder/AccountHolder.h)

