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

    vector<string> dependencies = parseYAML_Vector("dependencies");

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
