#ifndef NAVTOR_DIRECTORY_SERIALIZER_H
#define NAVTOR_DIRECTORY_SERIALIZER_H

#include <string>
#include "../proto/fs.pb.h"

class DirectorySerializer {
public:
    static int serializeDirectoryToFile(const mypackage::Directory& dir, const std::string& filename);
    static int deserializeFileToDirectory(mypackage::Directory& dir, const std::string& filename);
};

#endif //NAVTOR_DIRECTORY_SERIALIZER_H
