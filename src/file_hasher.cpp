#include "file_hasher.h"
#include <openssl/sha.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

typedef unsigned char ubyte_t;

static constexpr std::size_t s_block_size_4k = (1 << 12);

std::string FileHasher::calculateFileSha256(const std::string &file_path){
    std::ifstream ifs(file_path);
    char buffer[s_block_size_4k];

    std::vector<ubyte_t> sha_hash(SHA256_DIGEST_LENGTH, 0);

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    while(ifs.good()){
        ifs.read(buffer, s_block_size_4k);
        SHA256_Update(&ctx, buffer, ifs.gcount());
    }

    SHA256_Final(sha_hash.data(), &ctx);
    ifs.close();

    std::string hashStr;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hashStr += sha_hash[i];
    }

    return hashStr;
}