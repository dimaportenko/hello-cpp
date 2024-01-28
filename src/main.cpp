#include <fstream>
#include <iostream>
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
  int variantCompareAtIndex = -1;
  int variantPriceIndex = -1;

  while (getline(inputFile, line)) {
    // std::cout << "Processing line: " << line << std::endl;
    vector<string> columns = split(line, ',');
    // std::cout << lineCount << ". Number of columns: " << columns.size() << " : " << line  << std::endl;

    // if (lineCount == 201) {
    //     std::cout << "debug" << std::endl;
    // }

    if (lineCount == 0) {

      for (size_t i = 0; i < columns.size(); i++) {
        if (columns[i] == "Variant Compare At Price") {
          variantCompareAtIndex = i;
        }
        if (columns[i] == "Variant Price") {
          variantPriceIndex = i;
        }
      }

      if (variantCompareAtIndex == -1 || variantPriceIndex == -1) {
        std::cerr << "Required columns not found." << std::endl;
        return 1;
      }

    } else {
      // std::cout << "Processing line " << lineCount << std::endl;
      // std::cout << "Variant Compare At Price: " << columns[variantCompareAtIndex]
      //       << std::endl;
      // std::cout << "Variant Price: " << columns[variantPriceIndex] << std::endl;
      // swap compare at price and price
      std::swap(columns[variantCompareAtIndex], columns[variantPriceIndex]);
    }

    // write to output file
    for (size_t i = 0; i < columns.size(); i++) {
      outputFile << columns[i];

      // add comma if not last column
      if (i < columns.size() - 1) {
        outputFile << ",";
      }
    }
    outputFile << "\n";

    lineCount++;
  }

  inputFile.close();
  outputFile.close();

  std::cout << "Processing completed. Output file: " << outputFilepath
            << std::endl;

  return 0;
}
