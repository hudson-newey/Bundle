#include <bits/stdc++.h> // import may not be used
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>

// TODO: conert to 3d array
const string repoTemplateFiles[4] = { ".gitignore", "README.md", "LICENSE", bundlerFile.c_str() };
const string fileContents[4] = { "build/", string("# ") + string(findDir()), "", "# application information\n"
"appName : sample-application\n"
"description : this is a sample program...\n"
"author : <author>\n"
"version : 1.0\n"
"license : GNU General Public License 3.0\n"
"\n"
"# bundler info\n"
"bundle-version :\n"
"\n"
"# application source, runtime and build directory\n"
"runtime : runtime/\n"
"source : src/\n"
"scriptCount: 2\n"
"scripts:\n"
"  - 'go run main.go'\n"
"  - 'python3 fileServer.py'\n"
"" };
const string dirTemplate[3] = { "src", "build", "tests" };

void createDir(string dirName) {
    cout << "Creating Directory: " << dirName << endl;

    if (mkdir(dirName.c_str(), 0777) == -1) {
        cerr << "Error :  " << strerror(errno) << endl;
    }
}

void createFile(string file, string contents) {
    // Create UTF-8 text file
    cout << "Creating File: " << file << endl;
    ofstream MyFile(file);

    MyFile << contents << endl;
    MyFile.close();
}

void createRepoTemplate() {
    // create repo files (from template)
    for (int i = 0; i < sizeof(repoTemplateFiles)/sizeof(repoTemplateFiles[0]); i++) {
        createFile(repoTemplateFiles[i], fileContents[i]);
    }

    // create repo directories (from template)
    for (int i = 0; i < sizeof(dirTemplate)/sizeof(dirTemplate[0]); i++) {
        createDir(dirTemplate[i]);
    }
}
