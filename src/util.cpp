#include <iostream>
#include <string>
#include <unistd.h>

void printError(
    int errorCode = 1,
    std::string errorMessage = "An error occurred.",
    bool recoverable = false)
{
    std::cout << "\033[1;31m"
              << "Error (" << errorCode << "): " << errorMessage << "\033[0m"
              << "\n";

    if (!recoverable)
    {
        exit(errorCode);
    }
}

void printWarning(std::string warningMessage = "A warning occurred.")
{
    std::cout << "\033[1;33m"
              << "Warning: " << warningMessage << "\033[0m"
              << "\n";
}

void printInfo(std::string infoMessage = "An info message occurred.")
{
    std::cout << "\033[1;34m"
              << "Info: " << infoMessage << "\033[0m"
              << "\n";
}

// checks if the current calling user is a super user
bool isSu()
{
    return getuid() == 0;
}
