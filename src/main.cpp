#include <iostream>
#include <fstream>
#include <vector>

#include "split.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
    return 1;
  }

  string inputFilepath = argv[1];
  string outputFilepath = "output.csv";

  std::ifstream inputFile(inputFilepath);
  std::ofstream outputFile(outputFilepath);

  if (!inputFile.is_open()) {
    std::cerr << "Error: could not open file " << inputFilepath << std::endl;
    return 1;
  }

  if (!outputFile.is_open()) {
    std::cerr << "Error: could not open file " << outputFilepath << std::endl;
    return 1;
  }

  string line;
  int lineCount = 0;
  int variantCompareAtIndex = 0;
  int variantPriceIndex = 0;

  while (getline(inputFile, line)) {
    vector<string> columns = split(line, ',');
  }

  return 0;
}
