#include <fstream>

using namespace std;

bool fileExists(std::string fileName)
{
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

bool initBundler()
{
    // check a bundle file exists
    if (!fileExists("bundle.yaml")) {
        return false;
    }

    return true;
}
