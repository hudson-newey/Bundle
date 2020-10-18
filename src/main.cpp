// BUNDLER
// A framework to easily run, distribute and edit any language

#include <iostream>
#include "process/parse.cpp"
#include "run/main.cpp"
#include "init/main.cpp"

#include "addons/addons.h"

int main(int argc, char const *argv[])
{
    if (argc == 2) {
        // get CLI
        if (strcmp(argv[1], "run") == 0) {
            bundlerRun();
        } else if ((strcmp(argv[1], "init") == 0)) {
            bundlerInit();
        } else if ((strcmp(argv[1], "commit") == 0)) {
            gitCommit();
        }
    } else {
        // default is "bundler run"
        bundlerRun();
    }

    return 0;
}
