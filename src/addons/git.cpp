#include <iostream>
#include <string>

void gitCommit()
{
    // get user specified commit message
    std::cout << "(Commit Message) ";
    std::string commitMessage = "";
    getline(std::cin, commitMessage, '\n');

    // modify commit message to commit command
    commitMessage = "git commit -m \"" + commitMessage + "\"";

    // default git commit procedures
    system("git add --all");
    system(commitMessage.c_str());
    system("git push");
}
