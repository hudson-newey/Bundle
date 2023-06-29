using namespace std;

#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

void generateFromTemplate(string templateName)
{
    const string username = getenv("USERNAME");
    const auto source = "/home/" + username + "/.local/templates/" + templateName;
    const auto target = filesystem::current_path();

    try
    {
        filesystem::copy(source, target, filesystem::copy_options::skip_existing | filesystem::copy_options::recursive);
    }
    catch (const exception &e)
    {
        printError(1, e.what());
    }
}
