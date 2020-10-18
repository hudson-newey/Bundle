#include <fstream>

using namespace std;

bool fileExists(std::string fileName) {
   /* try to open file to read */
   ifstream ifile;
   ifile.open(fileName);
   if(ifile) {
      return true;
   } else {
      return false;
   }

   return false;
}

bool unitChecks() {
    // check a bundle file exists
    if (!fileExists("bundle.yaml")) {
        return false;
    }

    return true;
}

void initBundler() {
   bool validBundle = unitChecks();
    if (validBundle) {
        std::cout << parseYAML("appName") << " v" << parseYAML("version") << "\n\n";
    } else {
        std::cout << "Invalid Bundle File" << std::endl;
        exit(0);
    }
}
