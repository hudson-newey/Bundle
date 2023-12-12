#include <string.h>

void runScript(std::string command)
{
    char cmd[256];
    strcpy(cmd, command.c_str());
    system(cmd);
}
