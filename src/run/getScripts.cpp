#include "runScripts.cpp"

void getScriptsFromBundle() {
    for (int i = 0; i < std::stoi(parseYAML("scriptCount")); i++) {
        const std::string commandToRun = parseYAML_Vector("scripts", i);
        runScript(commandToRun);
    }
}
