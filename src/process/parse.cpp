using namespace std;

// yaml-cpp library
#include <string>
#include "yaml-cpp/yaml.h"
#include "../bundlerInfo.hpp"

string parseYAML(string parameter)
{
    YAML::Node basenode = YAML::LoadFile(BUNDLER_FILE);

    const string parameterAnswer = basenode[parameter].as<string>();
    return parameterAnswer;
}

vector<string> parseYAML_Vector(string parameter)
{
    YAML::Node basenode = YAML::LoadFile(BUNDLER_FILE);
    vector<string> result;

    for (const auto& node : basenode[parameter]) {
        result.push_back(node.as<string>());
    }

    return result;
}
