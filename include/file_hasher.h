#ifndef NAVTOR_FILE_HASHER_H
#define NAVTOR_FILE_HASHER_H

#include <string>
#include <vector>

typedef std::vector<unsigned char> sha256_t;

class FileHasher {
public:
    static sha256_t calculateFileSha256(const std::string& filePath);
};

#endif //NAVTOR_FILE_HASHER_H
