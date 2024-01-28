# src/utils/CMakeLists.txt

# Create a library 'utils' from the source file
add_library(utils STATIC split.cpp)

# Specify that the library includes headers from the current directory
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

