#include "csv.hpp" // Include the csv-parser header
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <input_file.csv> <output_file.csv>"
              << std::endl;
    return 1;
  }

  std::string inputFilePath = argv[1];
  std::string outputFilePath = argv[2];

  try {
    csv::CSVReader reader(inputFilePath);

    // Get index of the columns
    int variantCompareAtIndex = reader.index_of("Variant Compare At Price");
    int variantPriceIndex = reader.index_of("Variant Price");
    if (variantCompareAtIndex == -1 || variantPriceIndex == -1) {
      std::cerr << "Error: CSV does not contain required columns." << std::endl;
      return 1;
    }

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
      std::cerr << "Error: could not open file " << outputFilePath << std::endl;
      return 1;
    }

    // Write the header
    outputFile << "Variant Compare At Price,Variant Price" << std::endl;

    // Read and process each row
    for (csv::CSVRow &row : reader) {
      // Swap the values
      std::string temp = row[variantCompareAtIndex].get<>();
      row[variantCompareAtIndex].get<>() = row[variantPriceIndex].get<>();
      row[variantPriceIndex].get<>() = temp;

      // Write the modified row to the output file
      for (int i = 0; i < row.size(); ++i) {
        outputFile << row[i].get<>();
        if (i < row.size() - 1)
          outputFile << ",";
      }
      outputFile << std::endl;
    }

    outputFile.close();
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  std::cout << "File processing completed. Output file: " << outputFilePath
            << std::endl;
  return 0;
}
