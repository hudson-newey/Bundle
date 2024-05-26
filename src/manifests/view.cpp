#include "manifest.hpp"
#include <iostream>
#include <fstream>

void printManifest(std::string path)
{
    std::ifstream f(path);

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}

void viewManifest(Manifest manifest)
{
    std::string path = manifest.path;
    bool fileExists = std::ifstream(path).is_open();

    if (!fileExists)
    {
        printError(1, "Manifest '" + manifestName + "' does not exist");
    }

    printManifest(path);
}
