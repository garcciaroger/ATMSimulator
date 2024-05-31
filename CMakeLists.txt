cmake_minimum_required(VERSION 3.10)
project(ATMsim)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main application executable
add_executable(ATMsim 
    main.cpp 
    AccountHolder/AccountHolder.cpp 
    CheckingSaving/CheckingSaving.cpp 
    Program_Flow/program_flow.cpp 
    Program_Flow/supporting_functions.cpp
)

# Specify include directories for the main executable
target_include_directories(ATMsim PRIVATE 
    ${CMAKE_SOURCE_DIR}/AccountHolder 
    ${CMAKE_SOURCE_DIR}/CheckingSaving 
    ${CMAKE_SOURCE_DIR}/Program_Flow
)

# Add SQLite3 library
add_library(sqlite3 STATIC sqlite/sqlite3.c)

# Specify include directories for the SQLite library
target_include_directories(sqlite3 PRIVATE ${CMAKE_SOURCE_DIR})

# Link the main executable with SQLite
target_link_libraries(ATMsim sqlite3)

# Setup for GoogleTest
find_package(GTest REQUIRED)

# Add the test executables
add_executable(AccountTest 
    CheckingSaving/CheckingSaving_test.cpp
    CheckingSaving/CheckingSaving.cpp
)

add_executable(HolderTest 
    AccountHolder/AccountHolder_test.cpp
    AccountHolder/AccountHolder.cpp
)

# Specify include directories for the test executables
target_include_directories(HolderTest PRIVATE 
    ${CMAKE_SOURCE_DIR}/AccountHolder 
    ${CMAKE_SOURCE_DIR}/CheckingSaving 
    ${CMAKE_SOURCE_DIR}/Program_Flow
)

target_include_directories(AccountTest PRIVATE 
    ${CMAKE_SOURCE_DIR}/AccountHolder 
    ${CMAKE_SOURCE_DIR}/CheckingSaving 
    ${CMAKE_SOURCE_DIR}/Program_Flow
)

# Link GoogleTest to the test executables
target_link_libraries(HolderTest GTest::GTest GTest::Main)
target_link_libraries(AccountTest GTest::GTest GTest::Main)