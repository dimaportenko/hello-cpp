# src/CMakeLists.txt

# Add the utils subdirectory
add_subdirectory(utils)

# Create the main executable
add_executable(HelloWorld main.cpp)
set_target_properties(HelloWorld PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Link the executable with the utils library
target_link_libraries(HelloWorld PRIVATE utils)

