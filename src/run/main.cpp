#include "../process/findBundle.cpp"
#include "getScripts.cpp"

void bundleRun(std::vector<std::string> arguments)
{
    initBundle();
    getScriptsFromBundle(arguments);
}
