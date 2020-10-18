#include <iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void runScript(std::string command) {
   char cmd[256];
   strcpy(cmd, command.c_str());

   std::cout << command << std::endl;
   system(cmd); // comment out for debugging
}
