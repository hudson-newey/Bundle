using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "../bundlerInfo.hpp"

bool fileExists(string fileName)
{
    /* try to open file to read */
    ifstream file;
    file.open(fileName);
    if (file)
    {
        return true;
    }
    else
    {
        return false;
    }

    return false;
}

bool validateStructure()
{
    // check a bundle file exists
    if (!fileExists("bundle.yaml"))
    {
        cout << "\033[1;31mbundle.yaml Not Found!\033[0m" << "\n";
        return false;

        // check bundle version is compatible
    }
    else if (parseYAML("bundle-version") > BUNDLER_VERSION)
    {
        cout << "\033[1;31mIncompatible Bundler Version, Please Update...\033[0m" << "\n";
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
        cout << "\033[1;33m" << parseYAML("appName") << " v" << parseYAML("version") << "\033[0m" << "\n";
    }
    else
    {
        // bundler had a problem with the given "bundle.yaml" file
        cout << "\033[1;31mAn error had occurred while parsing the bundle.yaml file, please check the structure of the file and try again\033[0m" << "\n";
        exit(1);
    }
}
