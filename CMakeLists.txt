cmake_minimum_required(VERSION 3.10)
project(back_to_the)

set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(LibArchive REQUIRED)

# Generate protobuf C++ files
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS proto/fs.proto)

# Add your source files
set(SRCS
        main.cpp
        ${PROTO_SRCS}
        include/file_compressor.h include/file_hasher.h include/directory_processor.h include/directory_serializer.h include/archive_manager.h src/archive_manager.cpp src/directory_processor.cpp src/directory_serializer.cpp src/file_compressor.cpp src/file_hasher.cpp include/common.h)
add_subdirectory (minizip)

pkg_search_module(UUID REQUIRED uuid)
pkg_search_module(OPENSSL REQUIRED openssl)
pkg_search_module(CRYPTO REQUIRED libcrypto)

add_library(manager STATIC src/archive_manager.cpp src/directory_serializer.cpp src/directory_processor.cpp src/file_compressor.cpp src/file_hasher.cpp)

include_directories(
        ${UUID_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIRS}
        ${CRYPTO_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/minizip
        ${PROJECT_SOURCE_DIR}/include)

add_executable(back_to_the ${SRCS})
target_link_libraries(back_to_the manager lzma protobuf::libprotobuf archive minizip ${UUID_LIBRARIES} ${OPENSSL_LIBRARIES} ${CRYPTO_LIBRARIES} )
