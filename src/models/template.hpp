#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <string>
#include <vector>

class Template
{
public:
    Template(std::vector<std::string> directories);
    Template();

    std::vector<std::string> directories;

    Template* addPath(std::string path);
};

#endif
