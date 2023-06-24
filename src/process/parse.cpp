// yaml-cpp library
#include "yaml-cpp/yaml.h"

string parseYAML(string parameter) {
    YAML::Node basenode = YAML::LoadFile(bundlerFile);

    const string parameterAnswer = basenode[parameter].as<string>();
    return parameterAnswer;
}

string parseYAML_Vector(string parameter, int cell) {
    YAML::Node basenode = YAML::LoadFile(bundlerFile);

    string parameterAnswer = basenode[parameter][cell].as<string>();
    
    return parameterAnswer;
}
