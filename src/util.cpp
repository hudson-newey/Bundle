using namespace std;

#include <iostream>
#include <string>

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
