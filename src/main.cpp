#include <string>
#include <unistd.h>

#include "bundlerInfo.hpp"
#include "util.cpp"
#include "process/parse.cpp"
#include "run/main.cpp"
#include "new/new.cpp"
#include "init/main.cpp"
#include "system/ram.cpp"
#include "dependencies/verifyDependencies.cpp"
#include "dependencies/installDependencies.cpp"

#include "addons/addons.hpp"

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        const std::string command = argv[1];

        if (command == "-h" || command == "--help")
        {
            std::cout << BUNDLER_HELP_DOCS;
            return 0;
        }
        else if (command == "-v" || command == "--version")
        {
            std::cout << BUNDLER_VERSION << "\n";
            return 0;
        }

        // get CLI
        if (command == "run" || command == "r")
        {
            if (argc > 2) {
                const std::string templateName = argv[2];

                const std::string username = getlogin();
                const auto templatePath = "/home/" + username + "/.local/templates/" + templateName + ".yaml";

                BUNDLER_FILE = templatePath;
            }

            bundlerRun();
        }
        else if (command == "init")
        {
            bundlerInit();
        }
        else if (command == "commit")
        {
            gitCommit();
        }
        else if (command == "check" || command == "c")
        {
            if (argc > 2) {
                const std::string templateName = argv[2];

                const std::string username = getlogin();
                const auto templatePath = "/home/" + username + "/.local/templates/" + templateName + ".yaml";

                BUNDLER_FILE = templatePath;
            }

            verifyAllDependencies();
        }
        else if (command == "install" || command == "i")
        {
            if (argc > 2) {
                const std::string templateName = argv[2];

                const std::string username = getlogin();
                const auto templatePath = "/home/" + username + "/.local/templates/" + templateName + ".yaml";

                BUNDLER_FILE = templatePath;
            }

            installAllDependencies();
        }
        else if (command == "new" || command == "n")
        {

            if (argc == 2)
            {
                printError(1, "Must provide a template name after 'new' command\n\teg. bundler new <template-name>");
            }

            const std::string templateName = argv[2];
            generateFromTemplate(templateName);
        }
        else if (command == "ram")
        {

            if (argc == 2)
            {
                printError(1, "Must provide a command after 'ram' command\n\teg. bundler ram <load|unload> <filePath>");
            }

            const std::string ramCommand = argv[2];
            if (argc == 3 && ramCommand == "load")
            {
                printError(1, "Must provide a file name after 'ram load' command\n\teg. bundler ram <load|unload> <filePath>");
            }

            if (argc == 3 && ramCommand == "unload")
            {
                unloadPathFromRam();
            }
            else
            {
                const std::string fileName = argv[3];
                ramManipulate(ramCommand, fileName);
            }
        }
        else
        {
            printError(1, "Unknown command '" + command + "'");
        }
    }
    else
    {
        // default is "bundler run"
        bundlerRun();
    }

    return 0;
}
