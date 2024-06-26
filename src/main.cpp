#include <string>
#include <unistd.h>
#include <vector>
#include <map>

#include "bundleInfo.hpp"
#include "util.cpp"
#include "process/parse.cpp"
#include "run/environment/manager.cpp"
#include "run/environment/manifest.cpp"
#include "run/environment/environment.cpp"
#include "run/main.cpp"
#include "run/listScripts.cpp"
#include "run/viewScript.cpp"
#include "new/new.cpp"
#include "save/save.cpp"
#include "delete/delete.cpp"
#include "init/main.cpp"
#include "system/ram.cpp"
#include "dependencies/verifyDependencies.cpp"
#include "dependencies/installDependencies.cpp"

enum class Command
{
    RUN,
    INIT,
    CHECK,
    INSTALL,
    NEW,
    RAM,
    LIST,
    VIEW,
    SAVE,
    DELETE,
    ENVIRONMENT,

    // flags
    HELP,
    VERSION,
};

int main(int argc, const char *argv[])
{
    // default is "bundle run" if the program is run without any arguments
    if (argc == 1)
    {
        bundleRun({});
        return 0;
    }

    std::map<std::string, Command> claMap = {
        {"run", Command::RUN},
        {"r", Command::RUN},

        {"check", Command::CHECK},
        {"c", Command::CHECK},

        {"install", Command::INSTALL},
        {"i", Command::INSTALL},

        {"new", Command::NEW},
        {"n", Command::NEW},
        {"init", Command::INIT},

        {"list", Command::LIST},
        {"ls", Command::LIST},
        {"l", Command::LIST},

        {"save", Command::SAVE},
        {"s", Command::SAVE},

        {"view", Command::VIEW},
        {"v", Command::VIEW},

        {"env", Command::ENVIRONMENT},
        {"e", Command::ENVIRONMENT},

        {"delete", Command::DELETE},
        {"del", Command::DELETE},
        {"d", Command::DELETE},

        {"ram", Command::RAM},

        // flags
        {"--help", Command::HELP},
        {"-h", Command::HELP},
        {"--version", Command::VERSION},
        {"-v", Command::VERSION},
    };

    const std::string command = argv[1];

    switch (claMap[command])
    {
    case Command::HELP: {
        std::cout << BUNDLE_HELP_DOCS << "\n";
        break;
    }

    case Command::VERSION: {
        std::cout << BUNDLE_VERSION << "\n";
        break;
    }

    case Command::RUN: {
        std::vector<std::string> arguments;

        if (argc > 2)
        {
            const std::string templateName = argv[2];

            const std::string username = getlogin();
            const auto templatePath = "/home/" + username + "/.local/templates/" + templateName + ".yaml";

            BUNDLE_FILE = templatePath;

            for (int i = 3; i < argc; i++)
            {
                arguments.push_back(argv[i]);
            }
        }

        bundleRun(arguments);
        break;
    }

    case Command::ENVIRONMENT: {
        if (argc <= 2)
        {
            printError(1, "Must provide a command after 'env' command\n\teg. bundle env <load|unload> [manifest-name]");
        }

        const std::string environmentCommand = argv[2];

        if (argc <= 3)
        {
            printError(1, "Must provide a manifest name after '" + environmentCommand + "'\n\teg. bundle env <load|unload> <manifest-name>");
        }

        const std::string manifestName = argv[3];
        const std::string username = getlogin();
        const auto templatePath = "/home/" + username + "/.local/templates/" + manifestName + ".yaml";

        BUNDLE_FILE = templatePath;

        if (environmentCommand == "load")
        {
            activateEnvironment(manifestName);
        }
        else if (environmentCommand == "unload")
        {
            deactivateEnvironment(manifestName);
        }
        else if (environmentCommand == "delete")
        {
            destroyManifestEnvironment(manifestName);
        }
        else
        {
            printError(1, "Unknown argument '" + environmentCommand + "'");
        }

        break;
    }

    case Command::LIST: {
        listScripts();
        break;
    }

    case Command::VIEW: {
        if (argc <= 2)
        {
            printError(1, "Must provide an argument name after 'env' command\n\teg. bundle view <template-name>");
        }

        const std::string manifestName = argv[2];

        viewManifest(manifestName);
        break;
    }

    case Command::INIT: {
        bundleInit();
        break;
    }

    case Command::CHECK: {
        if (argc > 2)
        {
            const std::string checkTemplateName = argv[2];

            const std::string username = getlogin();
            const auto templatePath = "/home/" + username + "/.local/templates/" + checkTemplateName + ".yaml";

            BUNDLE_FILE = templatePath;
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

            BUNDLE_FILE = templatePath;
        }

        installAllDependencies();
        break;
    }

    case Command::NEW: {
        if (argc <= 2)
        {
            printError(1, "Must provide a template name after 'new' command\n\teg. bundle new <template-name>");
        }

        const std::string newTemplateName = argv[2];
        generateFromTemplate(newTemplateName);
        break;
    }

    case Command::SAVE: {
        if (argc <= 2)
        {
            printError(1, "Must provide a path after 'save' command\n\teg. bundle save <path> [template-name]");
        }

        const std::string templatePath = argv[2];

        if (argc <= 3)
        {
            saveTemplate(templatePath, templatePath);
            break;
        }

        const std::string templateName = argv[3];

        saveTemplate(templatePath, templateName);
        break;
    }

    case Command::DELETE: {
        if (argc <= 2)
        {
            printError(1, "Must provide a template name after 'delete' command\n\teg. bundle delete <template-name>");
        }

        const std::string templateName = argv[2];
        deleteTemplate(templateName);
        break;
    }

    case Command::RAM: {
        if (argc == 2)
        {
            printError(1, "Must provide a command after 'ram' command\n\teg. bundle ram <load|unload> <file-path>");
        }

        const std::string ramCommand = argv[2];
        if (argc == 3 && ramCommand == "load")
        {
            printError(1, "Must provide a file name after 'ram load' command\n\teg. bundle ram <load|unload> <file-path>");
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

    default: {
        printError(1, "Unknown command '" + command + "'");
        break;
    }
    }

    return 0;
}
