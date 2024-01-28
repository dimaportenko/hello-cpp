#include "csv.hpp"  // Include the csv-parser header
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file.csv> <output_file.csv>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];

    try {
        csv::CSVReader reader(inputFilePath);
        std::vector<std::vector<std::string>> rows;
        std::vector<std::string> headers = reader.get_col_names();
        int variantCompareAtIndex = -1;
        int variantPriceIndex = -1;

        // Find the index of the required columns
        for (size_t i = 0; i < headers.size(); i++) {
            if (headers[i] == "Variant Compare At Price") {
                variantCompareAtIndex = i;
            }
            if (headers[i] == "Variant Price") {
                variantPriceIndex = i;
            }
        }
        
        if (variantCompareAtIndex == -1 || variantPriceIndex == -1) {
            std::cerr << "Error: CSV does not contain required columns." << std::endl;
            return 1;
        }

        std::ofstream outputFile(outputFilePath);
        if (!outputFile.is_open()) {
            std::cerr << "Error: could not open file " << outputFilePath << std::endl;
            return 1;
        }

        // Write the header to the output file
        for (size_t i = 0; i < headers.size(); i++) {
            outputFile << headers[i];
            if (i < headers.size() - 1) outputFile << ",";
        }
        outputFile << std::endl;

        // Process rows
        for (csv::CSVRow& row : reader) {
            std::vector<std::string> rowData(row.size());
            for (size_t i = 0; i < row.size(); i++) {
                rowData[i] = row[i].get<>();
            }
            // Swap the values
            std::swap(rowData[variantCompareAtIndex], rowData[variantPriceIndex]);
            // Write the modified row to the output file
            for (size_t i = 0; i < rowData.size(); i++) {
                outputFile << rowData[i];
                if (i < rowData.size() - 1) outputFile << ",";
            }
            outputFile << std::endl;
        }
        
        outputFile.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "File processing completed. Output file: " << outputFilePath << std::endl;
    return 0;
}

