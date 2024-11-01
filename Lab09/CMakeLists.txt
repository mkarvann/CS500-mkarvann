cmake_minimum_required(VERSION 3.14)

# Set project name to MyString
set(this MyString)

# Defines the project and language
project(${this} CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# Include google test framework
add_subdirectory(googletest)

# Set our header files
set(Headers
    myString.h
)

# Set our source files
set(Sources
    myString.cpp
)

# Create library from our source code
add_library(${this} SHARED ${Sources} ${Headers})

# Set the name of our test executable
set(test myStringTest)

# Set our test source file
set(testSources
    test.cpp
)

# Create the test executable and link it
add_executable(${test} ${testSources})
target_link_libraries(${test} PUBLIC
    gtest_main
    ${this}
)

# Enable testing with ctest
add_test(
    NAME ${test}
    COMMAND ${test}
)