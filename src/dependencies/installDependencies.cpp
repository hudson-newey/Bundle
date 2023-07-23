using namespace std;

#include <iostream>
#include <cstdlib>

void installAllDependencies() {
    for (int i = 0; i < stoi(parseYAML("installCount")); i++)
    {
        const string installCommand = parseYAML_Vector("installCommands", i);
        runScript(installCommand);
    }
}
