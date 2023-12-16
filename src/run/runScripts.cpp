#include <string.h>

void runScript(std::string command, std::vector<std::string> arguments)
{
    char cmd[256];
    strcpy(cmd, command.c_str());

    for (int i = 0; i < arguments.size(); i++)
    {
        strcat(cmd, " ");
        strcat(cmd, arguments.at(i).c_str());
    }

    system(cmd);
}
