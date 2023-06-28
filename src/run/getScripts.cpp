using namespace std;

#include <string>

#include "runScripts.cpp"

void getScriptsFromBundle()
{
    for (int i = 0; i < stoi(parseYAML("scriptCount")); i++)
    {
        const string commandToRun = parseYAML_Vector("scripts", i);
        runScript(commandToRun);
    }
}
