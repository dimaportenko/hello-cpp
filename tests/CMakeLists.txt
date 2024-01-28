# tests/CMakeLists.txt

# Create the test executable
add_executable(split_test split_test.cpp)

# Add the test to CTest so that it runs with `make test` or `ctest`
add_test(NAME split_test COMMAND split_test)

# Link the executable with the utils library
target_link_libraries(split_test PRIVATE utils)

