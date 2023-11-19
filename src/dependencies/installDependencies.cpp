#include <iostream>
#include <cstdlib>

void installAllDependencies() {
    std::vector<std::string> installCommands = parseYAML_Vector("installCommands");

    for (int i = 0; i < installCommands.size(); i++)
    {
        runScript(installCommands[i]);
    }
}
