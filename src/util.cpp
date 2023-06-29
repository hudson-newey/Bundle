using namespace std;

#include <iostream>
#include <string>
#include <unistd.h>

void printError(
    int errorCode = 1,
    string errorMessage = "An error occurred.",
    bool recoverable = false
) {
    cout << "\033[1;31m" << "Error (" << errorCode << "): " << errorMessage << "\033[0m" << endl;

    if (!recoverable) {
        exit(errorCode);
    }
}

// checks if the current calling user is a super user
bool isSu() {
    return getuid() == 0;
}
