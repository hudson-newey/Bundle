using namespace std;

#include <iostream>
#include <cstdlib>

bool verifyDependency(string dependency) {
    // Using 'which' command to check if the desired command exists
    // If the command is found, 'which' returns 0
    int result = system(("which " + string(dependency)).c_str());
    return (result == 0);
}

bool verifyAllDependencies()
{
    bool foundError = false;

    for (int i = 0; i < stoi(parseYAML("dependencyCount")); i++)
    {
        const string dependencyToVerify = parseYAML_Vector("dependencies", i);
        const bool isSystemCommand = verifyDependency(dependencyToVerify);

        if (!isSystemCommand)
        {
            printError(2, "dependency " + dependencyToVerify + " is not installed on the system", true);
            foundError = true;
        }
    }

    return foundError;
}
