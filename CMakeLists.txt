cmake_minimum_required(VERSION 3.25)
project(ATMSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(ATMSimulator
        main.cpp AccountHolder/AccountHolder.cpp AccountHolder/AccountHolder.h AccountType/AccountType.cpp)
