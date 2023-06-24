#include <fstream>

bool fileExists(string fileName) {
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
        cout << "\033[1;31mbundle.yaml Not Found!\033[0m" << endl;
        return false;

    // check bundle version is compatible
    } else if (parseYAML("bundle-version") > bundlerVersion) {
        cout << "\033[1;31mIncompatible Bundler Version, Please Update...\033[0m" << endl;
        return false;
    }

    return true;
}

void initBundler() {
   bool validBundle = unitChecks();
    if (validBundle) {
        // start program and give CLI headers
        cout << "\033[1;33m" << parseYAML("appName") << " v" << parseYAML("version") << "\033[0m" << "\n\n";
    } else {
        // bundler had a problem with the given "bundle.yaml" file
        exit(0);
    }
}
