#include<string.h>

using namespace std;

void runScript(std::string command) {
   char cmd[256];
   strcpy(cmd, command.c_str());
   system(cmd); // comment out for debugging
}
