#include <fstream>
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    std::string filename;
    std::streampos byte_number;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--file") == 0) {
            if (i + 1 < argc) {
                filename = argv[++i];
            } else {
                std::cerr << "--file requires one argument." << std::endl;
                return 1;
            }
        } else if (strcmp(argv[i], "--byte_number") == 0) {
            if (i + 1 < argc) {
                byte_number = std::stoll(argv[++i]);
            } else {
                std::cerr << "--byte_number requires one argument." << std::endl;
                return 1;
            }
        }
    }

    // Open file
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return 1;
    }

    // Seek to byte_number
    file.seekg(byte_number);
    if (!file) {
        std::cerr << "Could not seek to byte number: " << byte_number << std::endl;
        return 1;
    }

    // Read byte
    char byte;
    file.read(&byte, 1);
    if (!file) {
        std::cerr << "Could not read byte at position: " << byte_number << std::endl;
        return 1;
    }

    // Output byte and return success
    std::cout << byte << std::endl;
    return 0;
}