# back_to_the

### Description

#### Purpose
This application prepares and generates archive from folder structure and recreates folder structure form this archive. 
It's dedicated to the folder structures with the same binary files with different names.


#### Usage
##### back_to_the - main functional application
Usage:
./back_to_the target <arg> {required args}

target options:

-c, --compress <directory_path> {-o <out>}
Create signature file

-x, --extract <archive_path> {-o <out>}
Create delta file

-h, --help                    Print help

arg options:

-o, --output <output_path>  Output file

#### Return data
* Program creates archive of given name
* Program recreates folder structure from self known archive

#### Documentation

https://tukaani.org/lzma/

#### Repositories

https://github.com/domoticz/minizip

https://github.com/jarro2783/cxxopts - input parser and help printer
