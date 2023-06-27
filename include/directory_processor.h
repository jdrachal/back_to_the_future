#ifndef NAVTOR_DIRECTORY_PROCESSOR_H
#define NAVTOR_DIRECTORY_PROCESSOR_H

#include <string>
#include <vector>
#include "file_hasher.h"
#include "../proto/fs.pb.h"

constexpr uint32_t MAX_FILES_NUMBER=1024*1024; // the number of files doesn’t exceed 1048576

class DirectoryProcessor {
public:
    DirectoryProcessor() : next_file_number_(1) {}
    void processDirectory(const std::string& directoryPath, mypackage::Directory* parentDir);


    static void clearTempData(const std::string& path);

    static bool createDirectory(const std::string& directoryPath);

private:

    void processFile(const std::string& path, const std::string& name, mypackage::Directory* parentDir);
    uint32_t next_file_number_;
};

#endif //NAVTOR_DIRECTORY_PROCESSOR_H
