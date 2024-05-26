#ifndef MANIFEST_H
#define MANIFEST_H

#include <string>
#include <vector>

class Manifest
{
public:
    std::string appName;
    std::string description;
    std::string author;
    std::string version;
    std::string license;
    std::string bundleVersion;
    std::string runtime;
    std::string source;
    std::vector<std::string> scripts;
    std::vector<std::string> dependencies;
    std::vector<std::string> installCommands;

    std::string path;

    Manifest();
};

#endif
