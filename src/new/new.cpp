#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

void generateFromTemplate(std::string templateName)
{
    const std::string username = getenv("USERNAME");
    const auto source = "/home/" + username + "/.local/templates/" + templateName;
    const auto target = std::filesystem::current_path();

    try
    {
        std::filesystem::copy(source, target, std::filesystem::copy_options::skip_existing | std::filesystem::copy_options::recursive);
    }
    catch (const std::exception &e)
    {
        printError(1, e.what());
    }
}
