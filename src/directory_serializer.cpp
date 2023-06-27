#include "directory_serializer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

int DirectorySerializer::serializeDirectoryToFile(const mypackage::Directory& dir, const std::string& filename){
    int serialized_size = dir.ByteSize();

    // Create a byte array to hold the serialized data
    std::vector<uint8_t> outBuff(serialized_size);

    // Serialize the message to the byte array
    if (!dir.SerializeWithCachedSizesToArray(outBuff.data())) {
        std::cerr << "Failed to serialize message to byte array." << std::endl;
        return 1;
    }

    // Write the serialized data to a file
    std::ofstream output(filename, std::ios::binary);
    if (!output) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }

    output.write(reinterpret_cast<const char *>(outBuff.data()), serialized_size);
    output.close(); // Close the file

    std::cout << "Metadata written to file." << std::endl;
    return 0;
}

int DirectorySerializer::deserializeFileToDirectory(mypackage::Directory& dir, const std::string& filename){

    std::ifstream input(filename, std::ios::binary);
    google::protobuf::io::IstreamInputStream istream(&input);
    google::protobuf::io::CodedInputStream coded_input(&istream);

    // Serialize the message to the byte array
    if (!dir.MergePartialFromCodedStream(&coded_input)) {
        std::cerr << "Failed to serialize message to byte array." << std::endl;
        return 1;
    }

    input.close(); // Close the file

    std::cout << "Message successfully read from file." << std::endl;
    return 0;
}
