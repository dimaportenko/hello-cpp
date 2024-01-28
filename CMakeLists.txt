cmake_minimum_required(VERSION 3.21)
project(HelloWorldProject)

set(CMAKE_CXX_STANDARD 20)

# Enable testing with CTest
enable_testing()

# Add subdirectories for the main application and tests
add_subdirectory(src)
add_subdirectory(tests)
# Root CMakeLists.txt
