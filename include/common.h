#ifndef NAVTOR_COMMON_H
#define NAVTOR_COMMON_H

#include <string>

constexpr uint32_t MAX_FILE_SIZE=2147483648;
const std::string DATA_ZIP_DIR="/tmp/navtor_data";
const std::string DATA_ZIP_METADATA=DATA_ZIP_DIR+"/metadata";
const std::string DATA_UNZIP_DIR="/tmp/navtor_unzip_data";
const std::string DATA_UNZIP_METADATA=DATA_UNZIP_DIR+"/metadata";

#endif //NAVTOR_COMMON_H
