// BUNDLER
// A framework to easily run, distribute and edit any language

#include <iostream>
#include "process/parse.cpp"
#include "process/findBundle.cpp"
#include "run/getScripts.cpp"

int main(int argc, char const *argv[])
{
    bool validBundle = initBundler();
    if (validBundle) {
        std::cout << parseYAML("appName") << " v" << parseYAML("version") << std::endl;
    } else {
        std::cout << "Invalid Bundle File" << std::endl;
        exit(0);
    }

    getScriptsFromBundle();
    return 0;
}
