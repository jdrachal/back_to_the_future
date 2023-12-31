#ifndef NAVTOR_FILE_COMPRESSOR_H
#define NAVTOR_FILE_COMPRESSOR_H

#include <string>

constexpr size_t bufferSize = 1024*1024*2;

class FileCompressor {
public:
    static void compressFile(const std::string& inputFile, const std::string& outputFile);
    static void decompressFile(const std::string& inputFile, const std::string& outputFile);
};

#endif //NAVTOR_FILE_COMPRESSOR_H
