#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <stdlib.h>

std::string ramDiskPartition = "/mnt/ram";

void loadPathToRam(std::string fileName) {
    std::string mkdirCommand = "mkdir " + ramDiskPartition;
    std::string mountCommand = "mount -t tmpfs -o size=128m tmpfs " + ramDiskPartition;

    try
    {
        // create ram disk partition
        system(mkdirCommand.c_str());
        system(mountCommand.c_str());

        // copy file to ramdisk partition
        const auto source = std::filesystem::current_path() / fileName;
        const auto target = ramDiskPartition;

        std::filesystem::copy(source, target, std::filesystem::copy_options::skip_existing | std::filesystem::copy_options::recursive);
    }
    catch (const std::exception &e)
    {
        printError(1, e.what());
    }

    std::cout << fileName << " is now available under " << ramDiskPartition << "/" << fileName << "\n";
    std::cout << "use 'bundle ram unload' to unload ramDisk" << "\n";
}

void unloadPathFromRam() {
    std::string removeDirCommand = "rm -rf " + ramDiskPartition;
    std::string unmountCommand = "umount " + ramDiskPartition;

    try
    {
        system(unmountCommand.c_str());
        system(removeDirCommand.c_str());
    }
    catch(const std::exception &e)
    {
        printError(1, e.what());
    }
}

void ramManipulate(std::string command, std::string fileName) {
    // check if the user is a super user
    if (!isSu()) {
        printError(1, "You must be a super user to use this command.");
    }

    if (command == "load") {
        loadPathToRam(fileName);
    } else if (command == "unload") {
        unloadPathFromRam();
    } else {
        printError(1, "Unknown ram operation '" + command + "'");
    }
}
