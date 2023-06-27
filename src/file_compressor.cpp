#include "file_compressor.h"
#include <lzma.h>
#include <iostream>
#include <fstream>
#include <array>
#include "common.h"

void FileCompressor::compressFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);

    lzma_stream strm = LZMA_STREAM_INIT;
    lzma_ret ret = lzma_easy_encoder(&strm, LZMA_PRESET_DEFAULT, LZMA_CHECK_CRC64);

    if (ret != LZMA_OK) {
        std::cerr << "Failed to initialize LZMA encoder." << std::endl;
        return;
    }

    std::array<uint8_t, bufferSize> inBuf;
    std::array<uint8_t, bufferSize> outBuf;

    strm.next_out = outBuf.data();
    strm.avail_out = outBuf.size();

    while (input.good()) {
        input.read(reinterpret_cast<char*>(inBuf.data()), bufferSize);
        strm.next_in = inBuf.data();
        strm.avail_in = input.gcount();

        while (strm.avail_in > 0) {
            ret = lzma_code(&strm, LZMA_RUN);

            if (ret != LZMA_OK) {
                std::cerr << "Failed to compress file." << std::endl;
                return;
            }

            if (strm.avail_out == 0) {
                output.write(reinterpret_cast<char*>(outBuf.data()), outBuf.size() - strm.avail_out);
                strm.next_out = outBuf.data();
                strm.avail_out = outBuf.size();
            }
        }
    }

    // Flush any remaining compressed data
    ret = lzma_code(&strm, LZMA_FINISH);

    if (ret != LZMA_OK && ret != LZMA_STREAM_END) {
        std::cerr << "Failed to compress file." << std::endl;
        return;
    }

    // Write the remaining compressed data
    output.write(reinterpret_cast<char*>(outBuf.data()), outBuf.size() - strm.avail_out);

    lzma_end(&strm);

    input.close();
    output.close();
}

void FileCompressor::decompressFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile, std::ios::binary);
    std::ofstream output(outputFile, std::ios::binary);

    lzma_stream strm = LZMA_STREAM_INIT;
    lzma_ret ret = lzma_stream_decoder(&strm, UINT64_MAX, LZMA_CONCATENATED);

    if (ret != LZMA_OK) {
        std::cerr << "Failed to initialize LZMA decoder." << std::endl;
        return;
    }

    std::array<uint8_t, bufferSize> inBuf;
    std::array<uint8_t, bufferSize> outBuf;

    strm.next_out = outBuf.data();
    strm.avail_out = outBuf.size();

    while (input.good()) {
        input.read(reinterpret_cast<char*>(inBuf.data()), bufferSize);
        strm.next_in = inBuf.data();
        strm.avail_in = input.gcount();

        while (strm.avail_in > 0) {
            ret = lzma_code(&strm, LZMA_RUN);

            if (ret != LZMA_OK && ret != LZMA_STREAM_END) {
                std::cerr << "Failed to decompress file." << std::endl;
                return;
            }

            if (strm.avail_out == 0) {
                output.write(reinterpret_cast<char*>(outBuf.data()), outBuf.size());
                strm.next_out = outBuf.data();
                strm.avail_out = outBuf.size();
            }
        }
    }

    // Write the remaining decompressed data
    output.write(reinterpret_cast<char*>(outBuf.data()), outBuf.size() - strm.avail_out);

    lzma_end(&strm);

    input.close();
    output.close();
}

