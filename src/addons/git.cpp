void gitCommit() {
    // get user specified commit message
    std::cout << "(Commit Message) ";
    std::string commitMessage = "";
    std::cin >> commitMessage;
    commitMessage = "git commit -m \"" + commitMessage + "\"";

    // default git commit procedures
    system("git add --all");
    system(commitMessage.c_str());
    system("git push");
}
