// yaml-cpp library
#include "yaml-cpp/yaml.h"
#include "../bundlerInfo.hpp"

std::string parseYAML(std::string parameter)
{
    YAML::Node basenode = YAML::LoadFile(BUNDLER_FILE);

    const std::string parameterAnswer = basenode[parameter].as<std::string>();
    return parameterAnswer;
}

std::vector<std::string> parseYAML_Vector(std::string parameter)
{
    YAML::Node basenode = YAML::LoadFile(BUNDLER_FILE);
    std::vector<std::string> result;

    for (const auto &node : basenode[parameter])
    {
        result.push_back(node.as<std::string>());
    }

    return result;
}
