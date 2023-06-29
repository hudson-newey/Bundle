using namespace std;

#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

string ramDiskPartition = "/mnt/ram";

void loadPathToRam(string fileName) {
    string mkdirCommand = "mkdir " + ramDiskPartition;
    string mountCommand = "mount -t tmpfs -o size=128m tmpfs " + ramDiskPartition;

    try
    {
        // create ram disk partition
        system(mkdirCommand.c_str());
        system(mountCommand.c_str());

        // copy file to ramdisk partition
        const auto source = filesystem::current_path() / fileName;
        const auto target = ramDiskPartition;

        filesystem::copy(source, target, filesystem::copy_options::skip_existing | filesystem::copy_options::recursive);
    }
    catch (const exception &e)
    {
        printError(1, e.what());
    }

    cout << fileName << " is now available under " << ramDiskPartition << "/" << fileName << endl;
    cout << "use 'bundler ram unload' to unload ramDisk" << endl;
}

void unloadPathFromRam() {
    string removeDirCommand = "rm -rf " + ramDiskPartition;
    string unmountCommand = "umount " + ramDiskPartition;

    try
    {
        system(unmountCommand.c_str());
        system(removeDirCommand.c_str());
    }
    catch(const exception &e)
    {
        printError(1, e.what());
    }
}

void ramManipulate(string command, string fileName) {
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
