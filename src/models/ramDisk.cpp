#include <iostream>
#include <filesystem>
#include <string>

#include "ramDisk.hpp"
#include "util/terminal.hpp"

#define RAM_DISK_PARTITION "/mnt/ram";

class RamDisk
{
public:
    RamDisk(std::string inPath) {
        this->inPath = inPath;
    }

    LOADED_SUCCESS load() {
        std::string mkdirCommand = "mkdir " RAM_DISK_PARTITION;
        std::string mountCommand = "mount -t tmpfs -o size=128m tmpfs " RAM_DISK_PARTITION;

        try
        {
            // create ram disk partition
            system(mkdirCommand.c_str());
            system(mountCommand.c_str());

            // copy file to ramdisk partition
            const auto source = std::filesystem::current_path() / this->inPath;
            const auto target = RAM_DISK_PARTITION;

            std::filesystem::copy(source, target, std::filesystem::copy_options::skip_existing | std::filesystem::copy_options::recursive);
        }
        catch (const std::exception &e)
        {
            Terminal::printError(1, e.what());
            return false;
        }

        // TODO: This terminal message should use the compiler macro
        std::cout << this->inPath << " is now available under " << "/mtn/ram/" << this->inPath << "\n";
        std::cout << "use 'bundle ram unload' to unload ramDisk" << "\n";
        return true;
    }

    LOADED_SUCCESS unload() {
        std::string removeDirCommand = "rm -rf " RAM_DISK_PARTITION;
        std::string unmountCommand = "umount " RAM_DISK_PARTITION;

        try
        {
            system(unmountCommand.c_str());
            system(removeDirCommand.c_str());
        }
        catch(const std::exception &e)
        {
            Terminal::printError(1, e.what());
            return false;
        }

        return true;
    }

private:
    std::string inPath;
};
