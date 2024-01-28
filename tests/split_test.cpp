#include "split.h"
#include <cassert>
#include <iostream>

void testSplit() {
  // Test case 1: Normal case
  {
    std::vector<std::string> result = split("a,b,c", ',');
    std::vector<std::string> expected = {"a", "b", "c"};
    assert(result == expected && "Test case 1 failed");
  }

  // Test case 2: Empty string
  {
    std::vector<std::string> result = split("", ',');
    std::vector<std::string> expected =
        {}; // Or {" "} if you expect a single empty string as a token
    assert(result == expected && "Test case 2 failed");
  }

  // Test case 3: Delimiter not present
  {
    std::vector<std::string> result = split("abc", ',');
    std::vector<std::string> expected = {"abc"};
    assert(result == expected && "Test case 3 failed");
  }

  // Test case 4: String ends with delimiter
  {
    std::vector<std::string> result = split("a,b,c,", ',');
    std::vector<std::string> expected = {
        "a", "b", "c",
        ""}; // Depends on how you want to handle trailing delimiters
    assert(result == expected && "Test case 4 failed");
  }

  // Test case 5: String starts with delimiter
  {
    std::vector<std::string> result = split(",a,b,c", ',');
    std::vector<std::string> expected = {
        "", "a", "b",
        "c"}; // Depends on how you want to handle leading delimiters
    assert(result == expected && "Test case 5 failed");
  }

  std::cout << "All test cases passed.\n";
}

int main() {
  testSplit();

  return 0;
}
