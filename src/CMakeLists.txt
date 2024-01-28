# src/CMakeLists.txt

# Add the utils subdirectory
add_subdirectory(utils)

# Create the main executable
add_executable(HelloWorld main.cpp)

# Link the executable with the utils library
target_link_libraries(HelloWorld PRIVATE utils)

