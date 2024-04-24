#include <filesystem>
#include <string>
#include <vector>
#include <stdlib.h>

// because environment variables are only inherited by child processes
// we need to start a new shell with the updated PATH environment variable
void startShell() {
    const std::string shell = getenv("SHELL");
    system(shell.c_str());
}

void activateEnvironment(std::string manifestName) {
    const std::string envLoc = manifestEnvLocation(manifestName);

    if (!std::filesystem::exists(envLoc)) {
        std::vector<std::string> dependencies = parseYAML_Vector("dependencies");

        createManifestEnvironment(manifestName, dependencies);
    }

    const std::string path = getenv("PATH");
    const std::string newPath = envLoc + ":" + path;
    if (setenv("PATH", newPath.c_str(), 1) != 0) {
        printError(1, "Failed to set environment for manifest " + manifestName);
        return;
    }

    printInfo("Environment for manifest " + manifestName + " activated");

    startShell();
}

void deactivateEnvironment(std::string manifestName) {
    const std::string envLoc = manifestEnvLocation(manifestName);

    const std::string path = getenv("PATH");
    const std::vector<std::string> paths = split(path, ':');
    std::string newPath = "";

    for (const std::string &p : paths) {
        if (p != envLoc) {
            newPath += p + ":";
        }
    }

    newPath.pop_back();
    setenv("PATH", newPath.c_str(), 1);
}
