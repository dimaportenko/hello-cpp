// split.cpp
#include "split.h"
#include <sstream>

std::vector<std::string> split(const std::string &str, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(str);

  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }

  // If the string ends with a delimiter, add an empty string to the vector
  if (!str.empty() && str.back() == delimiter) {
    tokens.push_back("");
  }

  return tokens;
}
