#include <iostream>
#include <fstream>
#include <string>
#include "../bundleInfo.hpp"

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
    if (!fileExists(BUNDLE_FILE))
    {
        printError(1, BUNDLE_FILE + " Not Found!");
        return false;

        // check bundle version is compatible
    }
    else if (parseYAML("bundle-version") > BUNDLE_VERSION)
    {
        printError(2, "Incompatible Bundle Version, Please Update...");
        return false;
    }

    return true;
}

void initBundle()
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
        // bundle had a problem with the given "bundle.yaml" file
        printError(1, "An error had occurred while parsing the bundle.yaml file, please check the structure of the file and try again");
    }
}
