#include <iostream>
#include <vector>
#include <dirent.h>
using namespace std;

void printSyntax() {
  cout << "Syntax:" << endl;
  cout << "img2vector [input-dir] [output-file]" << endl;
}

string getFileExt(string s) {
  size_t i  = s.rfind('.', s.length());
  if(i != string::npos) {
    return(s.substr(i+1, s.length() - i));
  }

  return("");
}

vector<string> fetchJpegFiles(string path) {
  DIR *dir;
  struct dirent *ent;
  vector<string> files;

  dir = opendir(path.c_str());

  while(ent = readdir(dir)) {
    if(getFileExt(ent->d_name) == "jpg") {
      files.push_back(path + "/" + ent->d_name);
    }
  }

  return files;
}

int main(int argc, char **argv) {
  if(argc != 3) {
    printSyntax();
    exit(-1);
  }

  vector<string> files = fetchJpegFiles(argv[1]);
  for(int i = 0; i < files.size(); i++) {
    cout << files.at(i) << endl;
  }
}
