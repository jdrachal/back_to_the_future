#include "archive_manager.h"
#include "directory_processor.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "minizip/zip.h"
#include "common.h"
#include "minizip/unzip.h"
#include "file_compressor.h"

namespace fs = std::filesystem;

void ArchiveManager::createArchive(){
    std::vector<std::string> fileNames;

    fs::path path(DATA_ZIP_DIR);
    if (!fs::is_directory(path))
    {
        if(!DirectoryProcessor::createDirectory(DATA_ZIP_DIR.c_str())) {
            return;
        }
    }

    struct dirent* entry;

    for (const auto& entry : fs::directory_iterator(path))
    {
        const std::string name = entry.path().filename().string();
        const std::string filePath = DATA_ZIP_DIR + "/" + name;

        if (fs::is_regular_file(entry.status()))
        {
            fileNames.push_back(name);
        }
    }

    zipFiles(fileNames, archive_dir_);
    DirectoryProcessor::clearTempData(DATA_ZIP_DIR);
}

void ArchiveManager::recreateDirectories(const mypackage::Directory& dir, const std::string& archiveDir, const std::string& outputDir){
    DirectoryProcessor::createDirectory(outputDir);

    for(int i = 0; i < dir.file_size();i++){
        FileCompressor::decompressFile(archiveDir+"/"+dir.file(i).data_filename(), outputDir+"/"+dir.file(i).name());
    }
    for(int i = 0; i < dir.directory_size();i++){
        recreateDirectories(dir.directory(i), archiveDir, outputDir+"/"+dir.directory(i).name());
    }
}

void ArchiveManager::zipFiles(const std::vector<std::string>& fileNames, const std::string& zipFileName)
{
    zipFile zip = zipOpen(zipFileName.c_str(), APPEND_STATUS_CREATE);
    if (!zip)
    {
        std::cerr << "Failed to create zip file: " << zipFileName << std::endl;
        return;
    }

    const int bufferSize = 4096;
    char buffer[bufferSize];

    for (const auto& fileName : fileNames)
    {
        std::ifstream file(DATA_ZIP_DIR + "/" + fileName, std::ios::binary);
        if (!file)
        {
            std::cerr << "Failed to open file: " << fileName << std::endl;
            continue;
        }

        zip_fileinfo fileInfo{};
        zipOpenNewFileInZip(zip, fileName.c_str(), &fileInfo, nullptr, 0, nullptr, 0, nullptr, Z_DEFLATED, Z_DEFAULT_COMPRESSION);

        while (file.good())
        {
            file.read(buffer, bufferSize);
            zipWriteInFileInZip(zip, buffer, static_cast<unsigned int>(file.gcount()));
        }

        file.close();
        zipCloseFileInZip(zip);
    }

    zipClose(zip, nullptr);

    std::cout << "Archive created successfully." << std::endl;
}

void ArchiveManager::unzipFiles(const std::string& zipFileName){
    unzFile unzip = unzOpen(zipFileName.c_str());
    if (!unzip)
    {
        std::cerr << "Failed to open zip file: " << zipFileName << std::endl;
        return;
    }

    unz_global_info globalInfo;
    if (unzGetGlobalInfo(unzip, &globalInfo) != UNZ_OK)
    {
        std::cerr << "Failed to retrieve global info from zip file: " << zipFileName << std::endl;
        unzClose(unzip);
        return;
    }

    char buffer[4096];
    for (uLong i = 0; i < globalInfo.number_entry; ++i)
    {
        unz_file_info fileInfo;
        char fileName[256];

        if (unzGetCurrentFileInfo(unzip, &fileInfo, fileName, sizeof(fileName), nullptr, 0, nullptr, 0) != UNZ_OK)
        {
            std::cerr << "Failed to retrieve file info from zip file: " << zipFileName << std::endl;
            break;
        }

        if (unzOpenCurrentFile(unzip) != UNZ_OK)
        {
            std::cerr << "Failed to open file in zip: " << fileName << std::endl;
            break;
        }

        std::string outputFilePath = DATA_UNZIP_DIR + "/" + fileName;
        std::ofstream outputFile(outputFilePath, std::ios::binary);
        if (!outputFile)
        {
            std::cerr << "Failed to create file: " << outputFilePath << std::endl;
            unzCloseCurrentFile(unzip);
            continue;
        }

        int bytesRead;
        while ((bytesRead = unzReadCurrentFile(unzip, buffer, sizeof(buffer))) > 0)
        {
            outputFile.write(buffer, bytesRead);
        }

        outputFile.close();
        unzCloseCurrentFile(unzip);

        unzGoToNextFile(unzip);
    }

    unzClose(unzip);
}

