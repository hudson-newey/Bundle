#include <filesystem>
#include <string>

std::string envLocation() {
    const std::string username = getlogin();
    return "/home/" + username + BUNDLE_ENV_ROOT;
}

std::string manifestEnvLocation(std::string manifestName) {
    const std::string envLoc = envLocation();
    return envLoc + "/" + manifestName;
}

void initEnvironment() {
    const std::string envLoc = envLocation();

    if (!std::filesystem::exists(envLoc)) {
        std::filesystem::create_directories(envLoc);
    }
}
