#include <iostream>
#include <fstream>

void printFile(std::string path)
{
    std::ifstream f(path);

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}

void viewManifest(std::string manifestName)
{
    std::string username = getlogin();
    std::string path = "/home/" + username + "/.local/templates/" + manifestName + ".yaml";

    if (!fileExists(path))
    {
        printError(1, "Manifest '" + manifestName + "' does not exist");
    }

    printFile(path);
}
