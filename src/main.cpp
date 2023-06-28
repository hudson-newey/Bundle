using namespace std;

#include <string>

#include "bundlerInfo.h"
#include "process/parse.cpp"
#include "run/main.cpp"
#include "new/new.cpp"
#include "init/main.cpp"
#include "util.cpp"

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

        } else {
            printError(1, "Unknown command" + command);
        }
    } else {
        // default is "bundler run"
        bundlerRun();
    }

    return 0;
}
