using namespace std;

#include <string>

#include "bundlerInfo.h"
#include "util.cpp"
#include "process/parse.cpp"
#include "run/main.cpp"
#include "new/new.cpp"
#include "init/main.cpp"
#include "system/ram.cpp"

#include "addons/addons.h"

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        const string command = argv[1];

        // get CLI
        if (command == "run") {
            bundlerRun();
        } else if (command == "init") {
            bundlerInit();
        } else if (command == "commit") {
            gitCommit();
        } else if (command == "new" || command == "n") {

            if (argc == 2) {
                printError(1, "Must provide a template name after 'new' command");
            }

            const string templateName = argv[2];
            generateFromTemplate(templateName);

        } else if (command == "ram") {

            if (argc == 2) {
                printError(1, "Must provide a command after 'ram' command");
            }

            const string ramCommand = argv[2];
            if (argc == 3 && ramCommand == "load") {
                printError(1, "Must provide a file name after 'ram load' command");
            }

            if (argc == 3 && ramCommand == "unload") {
                unloadPathFromRam();
            } else {
                const string fileName = argv[3];
                ramManipulate(ramCommand, fileName);
            }
        } else {
            printError(1, "Unknown command '" + command + "'");
        }
    } else {
        // default is "bundler run"
        bundlerRun();
    }

    return 0;
}
