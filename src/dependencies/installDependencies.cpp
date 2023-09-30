using namespace std;

#include <iostream>
#include <cstdlib>

void installAllDependencies() {
    vector<string> installCommands = parseYAML_Vector("installCommands");

    for (int i = 0; i < installCommands.size(); i++)
    {
        runScript(installCommands[i]);
    }
}
