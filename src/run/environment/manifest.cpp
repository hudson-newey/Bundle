#include <vector>
#include <filesystem>
#include <string>

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream stream (s);
    std::string item;

    while (getline(stream, item, delim)) {
        result.push_back(item);
    }

    return result;
}

std::string dependencyLocation(std::string dependency) {
    const std::string systemPath = getenv("PATH");
    const std::vector<std::string> paths = split(systemPath, ':');

    for (const std::string &path : paths) {
        const std::string depLoc = path + "/" + dependency;
        if (std::filesystem::exists(depLoc)) {
            return depLoc;
        }
    }

    return "";
}

void createManifestEnvironment(std::string manifestName, std::vector<std::string> dependencies) {
    printInfo("Creating environment for manifest " + manifestName);

    // creates the bundler home location to store the environment
    initEnvironment();

    const std::string envLoc = manifestEnvLocation(manifestName);

    if (std::filesystem::exists(envLoc)) {
        printWarning("Environment for manifest " + manifestName + " already exists");
        return;
    }

    std::filesystem::create_directory(envLoc);

    for (const std::string &dependency : dependencies) {
        const std::string depLoc = dependencyLocation(dependency);

        if (depLoc.empty()) {
            printWarning("Dependency " + dependency + " not found in PATH");
            continue;
        }

        const std::string envDepLoc = envLoc + "/" + dependency;
        std::filesystem::copy(depLoc, envDepLoc);
    }
}

void destroyManifestEnvironment(std::string manifestName) {
    const std::string envLoc = manifestEnvLocation(manifestName);
    std::filesystem::remove_all(envLoc);
}
