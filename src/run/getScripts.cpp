#include <string>
#include "runScripts.cpp"

void getScriptsFromBundle()
{
    std::vector<std::string> commandsToRun = parseYAML_Vector("scripts");

    for (int i = 0; i < commandsToRun.size(); i++)
    {
        runScript(commandsToRun[i]);
    }

}
