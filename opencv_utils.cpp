#include "../include/opencv_utils.hpp"

vector<double> OpenCVUtils::matToVector(Mat m, bool normalized) {
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

Mat OpenCVUtils::vectorToMat(vector<double> data, int rows, int cols) {
  Mat m(rows, cols, CV_8UC1);

  int i = 0;
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < cols; c++) {
      double val  = data.at(i);
      int intensity  = (int)(val * 255);
      m.at<uchar>(r, c) = (float)intensity;
      cout << i << ": " << (int)m.at<uchar>(r, c) << endl;
      i++;
    }
  }

  return m;
}
