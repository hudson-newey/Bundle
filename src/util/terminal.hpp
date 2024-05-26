#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>

namespace Terminal
{
    void printError( int errorCode = 1, std::string errorMessage = "An error occurred.", bool recoverable = false);

    void printWarning(std::string warningMessage = "A warning occurred.");

    void printInfo(std::string infoMessage = "An info message occurred.");
}

#endif
