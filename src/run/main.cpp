#include "../process/findBundle.cpp"
#include "getScripts.cpp"

void bundlerRun(std::vector<std::string> arguments)
{
    initBundler();
    getScriptsFromBundle(arguments);
}
