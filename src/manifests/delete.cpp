#include <iostream>
#include <filesystem>

void deleteTemplate(const std::string templateName)
{
    const std::string username = getlogin();
    const auto templatePath = "/home/" + username + "/.local/templates/" + templateName;

    if (!std::filesystem::exists(templatePath))
    {
        printError(1, "Template does not exist");
    }

    printWarning("Are you sure you want to delete " + templateName + "? (y/n)");

    do
    {
        std::string response;
        std::cin >> response;

        if (response == "y")
        {
            break;
        }
        else if (response == "n")
        {
            return;
        }
    } while (true);

    try
    {
        std::filesystem::remove_all(templatePath);
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        printError(1, e.what());
    }

    printInfo("Deleted template " + templateName);
}
