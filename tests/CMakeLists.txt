# Add the test executable
add_executable(split_test split_test.cpp ../src/split.cpp)

# Link the test executable with any necessary libraries
# target_link_libraries(split_test PRIVATE HelloWorld)

# Add the test to CTest so that it runs with `make test` or `ctest`
add_test(NAME split_test COMMAND split_test)

