using namespace std;

#include <iostream>
#include <string>

void gitCommit()
{
    // get user specified commit message
    cout << "(Commit Message) ";
    string commitMessage = "";
    getline(cin, commitMessage, '\n');

    // modify commit message to commit command
    commitMessage = "git commit -m \"" + commitMessage + "\"";

    // default git commit procedures
    system("git add --all");
    system(commitMessage.c_str());
    system("git push");
}
