#include <iostream>
#include "proto/fs.pb.h"
#include "directory_processor.h"
#include "directory_serializer.h"
#include "archive_manager.h"
#include "common.h"
#include "cxxopts.hpp"
#include <unistd.h>

static mypackage::Directory root_directory_proto;

int main(int argc, char* argv[]) {
    std::string output_path;

    cxxopts::Options options(argv[0], "Application for diffing files - cli options:");
    options
            .custom_help("target <arg>")
            .positional_help("{required args}")
            .show_positional_help();


    options
            .set_tab_expansion()
            .add_options("target")
                    ("c,compress", "Generate archive", cxxopts::value<std::string>(), "<directory_path> {-o <out>}")
                    ("x,extract", "Reconstruct dict from archive", cxxopts::value<std::string>(), "<archive_path> {-o <out>}")
                    ("h,help", "Print help");

    options
            .set_tab_expansion()
            .add_options("arg")
                    ("i,input", "Additional input file", cxxopts::value<std::string>(), "<file_path>")
                    ("o,output", "Output file", cxxopts::value<std::string>(), "<output_path>");

    options.parse_positional({"input", "output"});
    auto result = options.parse(argc, argv);
    if (result.count("help"))
    {
        std::cerr << options.help({"target", "arg"}) << std::endl;
        exit(0);
    }

    if (result.count("output")){
        output_path = result["output"].as<std::string>();
    } else {
        goto FinishHelp;
    }

    try {
        if (result.count("compress")) {
            std::string rootDirPath = result["compress"].as<std::string>();
            root_directory_proto.set_name(rootDirPath);
            DirectoryProcessor::createDirectory(DATA_ZIP_DIR);
            DirectoryProcessor().processDirectory(rootDirPath, &root_directory_proto);
            DirectorySerializer::serializeDirectoryToFile(root_directory_proto, DATA_ZIP_METADATA);
            ArchiveManager(output_path).createArchive();
        } else if (result.count("extract")) {
            std::string archDirPath = result["extract"].as<std::string>();
            DirectoryProcessor::createDirectory(DATA_UNZIP_DIR);
            ArchiveManager::unzipFiles(archDirPath);
            mypackage::Directory metadata;
            DirectorySerializer::deserializeFileToDirectory(metadata, DATA_UNZIP_METADATA);
            ArchiveManager::recreateDirectories(metadata, DATA_UNZIP_DIR, output_path);
            DirectoryProcessor::clearTempData(DATA_UNZIP_DIR);
        } else {
            goto FinishHelp;
        }
    } catch (std::invalid_argument &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;

    FinishHelp:
    std::cerr << options.help({"target", "arg"}) << std::endl;
    exit(0);
    /*
    std::string rootDirectory = "./CMakeFiles";

    root_directory.set_name(rootDirectory);
    processDirectory(rootDirectory, &root_directory);
    if (serializeDirectoryToFile(root_directory, metadata_file)) {
        std::cerr << "Failed to serialize message to file: " << metadata_file << std::endl;
        return 1;
    }

    createArchive();
    unzipFiles(archive_dir, "./out");

    mypackage::Directory received_metadata;
    deSerializeFileToDirectory(received_metadata, received_metadata_dir);

    recreateDirectories(received_metadata, "./out", "./final");

    */

}
