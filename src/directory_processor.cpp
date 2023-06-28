#include "directory_processor.h"
#include "file_hasher.h"
#include "file_compressor.h"
#include "common.h"
#include "../proto/fs.pb.h"
#include <iostream>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;

std::unordered_map<std::string, uint32_t> file_map;

bool DirectoryProcessor::createDirectory(const std::string& directoryPath)
{
    fs::path path(directoryPath);

    try {
        if (fs::create_directories(path)) {
            std::cerr << "Directory created successfully." << std::endl;
            return true;
        } else {
            std::cerr << "Error occurred during directory creation." << std::endl;
            return false;
        }
    } catch (const std::filesystem::filesystem_error& ex) {
        std::cerr << "Error occurred during directory creation: " << ex.what() << std::endl;
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
    fs::path directoryPath(path);

    if (!fs::is_directory(directoryPath))
    {
        std::cerr << "Failed to open directory: " << path << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(directoryPath))
    {
        const std::string entryName = entry.path().filename().string();

        if (entryName != "." && entryName != "..")
        {
            const fs::path entryPath = entry.path();

            if (fs::is_regular_file(entryPath))
            {
                if (!fs::remove(entryPath))
                {
                    std::cerr << "Failed to remove file: " << entryPath << std::endl;
                }
            }
            else if (fs::is_directory(entryPath))
            {
                clearTempData(entryPath.string());

                if (!fs::remove(entryPath))
                {
                    std::cerr << "Failed to remove directory: " << entryPath << std::endl;
                }
            }
            else
            {
                std::cerr << "Failed to get file status: " << entryPath << std::endl;
            }
        }
    }

    if (!fs::remove(directoryPath))
    {
        std::cerr << "Failed to remove directory: " << directoryPath << std::endl;
    }
}

void DirectoryProcessor::processDirectory(const std::string& directoryPath, mypackage::Directory* parentDir){
    fs::path path(directoryPath);

    if (!fs::is_directory(path))
    {
        std::cerr << "Failed to open directory: " << directoryPath << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(path))
    {
        const std::string name = entry.path().filename().string();
        const std::string entryPath = entry.path().string();

        const fs::file_status status = entry.status();

        if (fs::is_regular_file(status))
        {
            processFile(entryPath, name, parentDir);
        }
        else if (fs::is_directory(status) && name != "." && name != "..")
        {
            mypackage::Directory* subDir = parentDir->add_directory();
            subDir->set_name(name);
            processDirectory(entryPath, subDir);
        }
    }
}