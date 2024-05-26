#include <iostream>
#include <cstdlib>

bool verifyDependency(std::string dependency)
{
    // Using 'which' command to check if the desired command exists
    // If the command is found, 'which' returns 0
    int result = system(("which " + std::string(dependency)).c_str());
    return (result == 0);
}

bool verifyAllDependencies()
{
    initBundle();

    bool foundError = false;

    std::vector<std::string> dependencies = parseYAML_Vector("dependencies");

    if (dependencies.size() == 0)
    {
        printWarning("No dependencies detected.");
        return foundError;
    }

    for (int i = 0; i < dependencies.size(); i++)
    {
        const bool isSystemCommand = verifyDependency(dependencies[i]);

        if (!isSystemCommand)
        {
            printError(2, "dependency " + dependencies[i] + " is not installed on the system", true);
            foundError = true;
        }
    }

    return foundError;
}
