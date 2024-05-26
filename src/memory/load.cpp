void loadPathToRam(std::string fileName)
{
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
