// BUNDLER
// A framework to easily run, distribute and edit any language

#include <iostream>
#include "parse.cpp"

int main(int argc, char const *argv[])
{
    for (int i = 0; i < std::stoi(parseYAML("scriptCount")); i++)
    {
        std::cout << parseYAML_Vector("scripts", i) << std::endl;
    }
    
    return 0;
}
