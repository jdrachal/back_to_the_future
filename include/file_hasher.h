#ifndef NAVTOR_FILE_HASHER_H
#define NAVTOR_FILE_HASHER_H

#include <string>
#include <vector>

class FileHasher {
public:
    static std::string calculateFileSha256(const std::string& filePath);
};

#endif //NAVTOR_FILE_HASHER_H
