#ifndef RAMDISK_H
#define RAMDISK_H

#include <string>

#define LOADED_SUCCESS bool

class RamDisk
{
public:
    RamDisk(std::string inPath);

    LOADED_SUCCESS load();
    LOADED_SUCCESS unload();
};

#endif
