#ifndef NAVTOR_ARCHIVE_MANAGER_H
#define NAVTOR_ARCHIVE_MANAGER_H

#include <string>
#include <vector>
#include "../proto/fs.pb.h"

class ArchiveManager {
public:
    ArchiveManager(std::string archive_dir) : archive_dir_(archive_dir) {}
    void createArchive();
    static void recreateDirectories(const mypackage::Directory& dir, const std::string& archiveDir, const std::string& outputDir);
    static void unzipFiles(const std::string& zipFileName);
private:
    std::string archive_dir_;

    void zipFiles(const std::vector<std::string>& fileNames, const std::string& zipFileName);
};

#endif //NAVTOR_ARCHIVE_MANAGER_H
