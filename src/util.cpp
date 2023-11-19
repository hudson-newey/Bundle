#include <iostream>
#include <string>
#include <unistd.h>

void printError(
    int errorCode = 1,
    std::string errorMessage = "An error occurred.",
    bool recoverable = false
) {
    std::cout << "\033[1;31m" << "Error (" << errorCode << "): " << errorMessage << "\033[0m" << "\n";

    if (!recoverable) {
        exit(errorCode);
    }
}

// checks if the current calling user is a super user
bool isSu() {
    return getuid() == 0;
}
