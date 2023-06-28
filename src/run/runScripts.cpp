using namespace std;

#include <string.h>

void runScript(string command) {
   char cmd[256];
   strcpy(cmd, command.c_str());
   system(cmd); // comment out for debugging
}
