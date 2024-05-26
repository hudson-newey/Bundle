#include "template.hpp"
#include <string>
#include <vector>

class Template
{
public:
    Template(std::vector<std::string> directories)
    {
        this->directories = directories;
    }

    Template() {}

    Template* addPath(std::string path) {
        return this;
    }

private:
    std::vector<std::string> directories;
};
