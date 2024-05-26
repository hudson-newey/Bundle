#include "manifest.hpp"
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

    Manifest(
        std::string appName,
        std::string description,
        std::string author,
        std::string version,
        std::string license,
        std::string bundleVersion,
        std::string runtime,
        std::string source,
        std::vector<std::string> scripts,
        std::vector<std::string> dependencies,
        std::vector<std::string> installCommands
    ) {
        this->appName = appName;
        this->description = description;
        this->author = author;
        this->version = version;
        this->bundleVersion = bundleVersion;
        this->runtime = runtime;
        this->source = source;
        this->scripts = scripts;
        this->dependencies = dependencies;
        this->installCommands = installCommands;
    };
};
