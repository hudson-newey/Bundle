#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include<iostream>
using namespace std;

//function to get lastt index of a character 
int getLastIndex(char *s, char c)
{
	int length;
	int i; //loop counter
	//get length
	length = strlen(s);
	
	//run loop from length-1 to 0
	for(i=(length-1); i>=0; i--)
	{
		//compare character with each charater of string
		if(s[i]==c)
			return i; //character found return index
	}
	
	//if character not found return -1
	return -1;
}


std::string findDir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir( buff, FILENAME_MAX );
	char* current_working_dir(buff);

	// remove directory and keep directory name
	return std::string(current_working_dir).erase(0, getLastIndex(current_working_dir, '/') + 1);
}