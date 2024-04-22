#include <string>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> listPathFiles(std::string path)
{
    std::vector<std::string> result;

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        result.push_back(entry.path().string());
    }

    return result;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream stream (s);
    std::string item;

    while (getline(stream, item, delim)) {
        result.push_back(item);
    }

    return result;
}

void listScripts()
{
    const std::string username = getlogin();
    const std::string templatePath = "/home/" + username + "/.local/templates/";

    const std::vector<std::string> paths = listPathFiles(templatePath);

    if (paths.empty())
    {
        printWarning("No manifests found");
        std::cout << "Create new manifests in ~/.local/templates" << "\n";
        return;
    }

    // templates can be created using the `bundle new` command
    // while manifests can be run, installed, etc.. using the `bundler run` and `bundler install` commands
    // templates are re-usuable files to copy into your projects, while manifests are re-usuable scripts
    std::vector<std::string> templates {};
    std::vector<std::string> manifests {};

    for (const std::string path : paths)
    {
        const std::vector<std::string> splitPath = split(path, '/');

        const std::string file = splitPath.back();

        // manifests always end with .yaml
        // additionally, everything in the templates directory can be used as a template (even manifests)
        // therefore, we can label everything that doesn't end with .yaml as a template
        if (file.find(".yaml") != std::string::npos) {
            manifests.push_back(file);
        } else {
            templates.push_back(file);
        }
    }

    // templates heading should be in bright magenta (see ansii color codes for more info)
    std::cout << "\033[1;94m" << "Templates" << "\033[0m" << "\n";
    for (const std::string templateName : templates)
    {
        std::cout << "\t" << templateName << "\n";
    }

    // templates heading should be in bright cyan
    std::cout << "\n\033[1;95m" << "Manifests" << "\033[0m" << "\n";
    for (const std::string manifestName : manifests)
    {
        std::cout << "\t" << manifestName << "\n";
    }
}
