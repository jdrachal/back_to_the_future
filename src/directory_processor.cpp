#include "directory_processor.h"
#include "file_hasher.h"
#include "file_compressor.h"
#include "common.h"
#include <sys/stat.h>
#include <dirent.h>
#include "../proto/fs.pb.h"
#include <iostream>
#include <unistd.h>
#include <unordered_map>

std::unordered_map<std::string, uint32_t> file_map;

bool DirectoryProcessor::createDirectory(const std::string& directoryPath)
{
    int status = mkdir(directoryPath.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (status == 0) {
        std::cerr << "Directory created successfully." << std::endl;
        return true;
    }
    else {
        std::cerr << "Error occurred during directory creation." << std::endl;
        return false;
    }
}

void DirectoryProcessor::processFile(const std::string& path, const std::string& name, mypackage::Directory* parentDir){
    auto f = parentDir->add_file();
    f->set_name(name);
    auto hash = FileHasher::calculateFileSha256(path);
    if(file_map.find(hash) != file_map.end()){
        f->set_data_filename(std::to_string(file_map[hash]));
    } else {
        FileCompressor::compressFile(path, DATA_ZIP_DIR + "/" + std::to_string(next_file_number_));
        file_map.insert(std::make_pair(hash, next_file_number_));
        f->set_data_filename(std::to_string(next_file_number_++));
    }
}

void DirectoryProcessor::clearTempData(const std::string& path) {
    DIR* dir = opendir(path.c_str());
    if (dir == nullptr) {
        std::cerr << "Failed to open directory: " << path << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string entryName = entry->d_name;
        if (entryName != "." && entryName != "..") {
            std::string entryPath = path + "/" + entryName;
            struct stat entryStat;
            if (lstat(entryPath.c_str(), &entryStat) == 0) {
                if (S_ISREG(entryStat.st_mode)) {
                    // Entry is a directory
                    if (unlink(entryPath.c_str()) != 0) {
                        std::cerr << "Failed to remove file: " << entryPath << std::endl;
                    }
                }
            } else {
                std::cerr << "Failed to get file status: " << entryPath << std::endl;
            }
        }
    }

    closedir(dir);

    if (rmdir(path.c_str()) != 0) {
        std::cerr << "Failed to remove directory: " << path << std::endl;
    }
}

void DirectoryProcessor::processDirectory(const std::string& directoryPath, mypackage::Directory* parentDir){
    DIR* dir = opendir(directoryPath.c_str());
    if (dir == nullptr)
    {
        std::cerr << "Failed to open directory: " << directoryPath << std::endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr)
    {
        std::string name = entry->d_name;
        std::string path = directoryPath + "/" + name;

        struct stat st;
        if (stat(path.c_str(), &st) == 0)
        {
            if (S_ISREG(st.st_mode))
            {
                // Process regular file
                processFile(path, name, parentDir);

            }
            else if (S_ISDIR(st.st_mode) && name != "." && name != "..")
            {
                auto d = parentDir->add_directory();
                d->set_name(name);
                // Recursively process subdirectory
                processDirectory(path, d);
            }
        }
    }

    closedir(dir);
}