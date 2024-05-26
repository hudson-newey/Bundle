#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <stdlib.h>

namespace Ram
{
    void ramManipulate(std::string command, std::string fileName)
    {
        if (!isSu())
        {
            printError(1, "You must be a super user to use this command.\nTry running again with sudo");
        }

        if (command == "load")
        {
            loadPathToRam(fileName);
        }
        else if (command == "unload")
        {
            unloadPathFromRam();
        }
        else
        {
            printError(1, "Unknown ram operation '" + command + "'");
        }
    }
}
