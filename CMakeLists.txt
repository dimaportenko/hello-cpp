cmake_minimum_required(VERSION 3.21)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)

# Enable testing with CTest
enable_testing()

# Add your main application's source directory
add_subdirectory(src)

# Add your test directory
add_subdirectory(tests)
