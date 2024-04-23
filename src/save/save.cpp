#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

bool endsWith(const std::string s, const std::string suffix)
{
    return s.rfind(suffix) == (s.size() - suffix.size());
}

// a path is a manifest if it ends with .yaml or .yml
bool isManifest(const std::string path)
{
    return endsWith(path, ".yaml") || endsWith(path, ".yml");
}

void saveTemplate(const std::string templatePath, const std::string templateName)
{
    const auto source = std::filesystem::path(templatePath);

    const std::string username = getlogin();
    auto destination = "/home/" + username + "/.local/templates/" + templateName;

    if (std::filesystem::exists(destination))
    {
        printError(1, "Template already exists");
    }

    try
    {
        std::filesystem::copy(source, destination);
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        printError(1, e.what());
    }

    if (isManifest(templatePath))
    {
        printInfo("Saved manifest " + templateName);
        printInfo("Use this manifest by running 'bundle run " + templateName + "'");
        return;
    }

    printInfo("Saved template " + templateName);
    printInfo("Use this template by running 'bundle new " + templateName + "'");
}
