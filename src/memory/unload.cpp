void unloadPathFromRam()
{
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
