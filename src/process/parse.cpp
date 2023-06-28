using namespace std;

// yaml-cpp library
#include <string>
#include "yaml-cpp/yaml.h"
#include "../bundlerInfo.h"

string parseYAML(string parameter)
{
    YAML::Node basenode = YAML::LoadFile(BUNDLER_FILE);

    const string parameterAnswer = basenode[parameter].as<string>();
    return parameterAnswer;
}

string parseYAML_Vector(string parameter, int cell)
{
    YAML::Node basenode = YAML::LoadFile(BUNDLER_FILE);

    string parameterAnswer = basenode[parameter][cell].as<string>();

    return parameterAnswer;
}
