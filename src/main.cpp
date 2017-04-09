#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

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

vector<double> matToVector(Mat m, bool normalized) {
  assert(m.channels() == 1);
  vector<double> data;

  for(int r = 0; r < m.rows; r++) {
    for(int c = 0; c < m.cols; c++) {
      double val = (double)m.at<uchar>(r, c);

      if(normalized) {
        val = val / 255;
      }

      data.push_back(val);
    }
  }

  return data;
}

int main(int argc, char **argv) {
  if(argc != 3) {
    printSyntax();
    exit(-1);
  }

  vector<string> files  = fetchJpegFiles(argv[1]);
  string outputFilename = argv[2];

  vector< vector<double> > data;  // data variable to hold output
  ofstream fs;                    // file output stream

  fs.open(outputFilename.c_str());

  // Store in vector
  for(int i = 0; i < files.size(); i++) {
    Mat m = imread(files.at(i), 0);
    data.push_back(matToVector(m, true));
  }

  // Print to csv
  for(int i = 0; i < data.size(); i++) {
    for(int j = 0; j < data.at(i).size(); j++) {
      fs << data.at(i).at(j);

      if(j != (data.at(i).size() - 1)) {
        fs << ",";
      } else {
        fs << endl;
      }
    }
  }

  fs.close();

  cout << "Done." << endl;
  return 0;
}
