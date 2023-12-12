#include <string>
#include "runScripts.cpp"

void getScriptsFromBundle()
{
    std::vector<std::string> commandsToRun = parseYAML_Vector("scripts");

    if (commandsToRun.size() == 0)
    {
        printWarning("No scripts detected.");
        return;
    }

    for (int i = 0; i < commandsToRun.size(); i++)
    {
        runScript(commandsToRun[i]);
    }
}
