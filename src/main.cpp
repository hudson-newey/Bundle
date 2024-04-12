#include <string>
#include <unistd.h>
#include <vector>
#include <map>

#include "bundlerInfo.hpp"
#include "util.cpp"
#include "process/parse.cpp"
#include "run/main.cpp"
#include "run/listScripts.cpp"
#include "new/new.cpp"
#include "init/main.cpp"
#include "system/ram.cpp"
#include "dependencies/verifyDependencies.cpp"
#include "dependencies/installDependencies.cpp"

#include "addons/addons.hpp"

enum class Command
{
    RUN,
    INIT,
    CHECK,
    INSTALL,
    NEW,
    RAM,
    LIST,

    // flags
    HELP,
    VERSION,

    // addons
    COMMIT
};

int main(int argc, const char *argv[])
{
    // default is "bundler run" if the program is run without any arguments
    if (argc == 1)
    {
        bundlerRun({});
        return 0;
    }

    std::map<std::string, Command> claMap = {
        {"run", Command::RUN},
        {"r", Command::RUN},
        {"init", Command::INIT},
        {"check", Command::CHECK},
        {"c", Command::CHECK},
        {"install", Command::INSTALL},
        {"i", Command::INSTALL},
        {"new", Command::NEW},
        {"n", Command::NEW},
        {"ram", Command::RAM},

        {"list", Command::LIST},
        {"ls", Command::LIST},
        {"l", Command::LIST},

        // flags
        {"--help", Command::HELP},
        {"-h", Command::HELP},
        {"--version", Command::VERSION},
        {"-v", Command::VERSION},

        // addons
        {"commit", Command::COMMIT}
    };

    const std::string command = argv[1];

    switch (claMap[command])
    {
    case Command::HELP: {
        std::cout << BUNDLER_HELP_DOCS << "\n";
        break;
    }

    case Command::VERSION: {
        std::cout << BUNDLER_VERSION << "\n";
        break;
    }

    case Command::RUN: {
        std::vector<std::string> arguments;

        if (argc > 2)
        {
            const std::string templateName = argv[2];

            const std::string username = getlogin();
            const auto templatePath = "/home/" + username + "/.local/templates/" + templateName + ".yaml";

            BUNDLER_FILE = templatePath;

            for (int i = 3; i < argc; i++)
            {
                arguments.push_back(argv[i]);
            }
        }

        bundlerRun(arguments);
        break;
    }

    case Command::LIST: {
        listScripts();
        break;
    }

    case Command::INIT: {
        bundlerInit();
        break;
    }

    case Command::CHECK: {
        if (argc > 2)
        {
            const std::string checkTemplateName = argv[2];

            const std::string username = getlogin();
            const auto templatePath = "/home/" + username + "/.local/templates/" + checkTemplateName + ".yaml";

            BUNDLER_FILE = templatePath;
        }

        verifyAllDependencies();
        break;
    }

    case Command::INSTALL: {
        if (argc > 2)
        {
            const std::string installTemplateName = argv[2];

            const std::string username = getlogin();
            const auto templatePath = "/home/" + username + "/.local/templates/" + installTemplateName + ".yaml";

            BUNDLER_FILE = templatePath;
        }

        installAllDependencies();
        break;
    }

    case Command::NEW: {
        if (argc <= 2)
        {
            printError(1, "Must provide a template name after 'new' command\n\teg. bundler new <template-name>");
        }

        const std::string newTemplateName = argv[2];
        generateFromTemplate(newTemplateName);
        break;
    }

    case Command::RAM: {
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
        break;
    }

    // addons
    case Command::COMMIT: {
        gitCommit();
        break;
    }

    default: {
        printError(1, "Unknown command '" + command + "'");
        break;
    }
    }

    return 0;
}
