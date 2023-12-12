#include <iostream>
#include <fstream>
#include <string>
#include "../bundlerInfo.hpp"

bool fileExists(std::string fileName)
{
    std::ifstream file;

    file.open(fileName);

    if (file)
    {
        return true;
    }

    return false;
}

bool validateStructure()
{
    // check a bundle file exists
    if (!fileExists(BUNDLER_FILE))
    {
        printError(1, BUNDLER_FILE + " Not Found!");
        return false;

        // check bundle version is compatible
    }
    else if (parseYAML("bundle-version") > BUNDLER_VERSION)
    {
        printError(2, "Incompatible Bundler Version, Please Update...");
        return false;
    }

    return true;
}

void initBundler()
{
    bool validBundle = validateStructure();
    if (validBundle)
    {
        // start program and give CLI headers
        std::cout << "\033[1;33m" << parseYAML("appName") << " v" << parseYAML("version") << "\033[0m"
                  << "\n";
    }
    else
    {
        // bundler had a problem with the given "bundle.yaml" file
        printError(1, "An error had occurred while parsing the bundle.yaml file, please check the structure of the file and try again");
    }
}
