#include "opencv4/opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int test_case() {
  /** The final argument is optional. If given the image will be loaded in gray
   * scale format, otherwise the BGR color space is used. The first thing is to
   * calculate the lookup table.
   */
  int divideWith = 0;  // convert our input string to number - C++ style
  stringstream s;
  s << "our test case";
  s >> divideWith;
  if (!s || !divideWith) {
    cout << "Invalid number entered for dividing. " << endl;
    return -1;
  }
  uchar table[256];
  for (int i = 0; i < 256; ++i)
    table[i] = (uchar)(divideWith * (i / divideWith));

  // Another issue is how do we measure time
  double t = (double)getTickCount();
  // do something ...
  t = ((double)getTickCount() - t) / getTickFrequency();
  cout << "Times passed in seconds: " << t << endl;
  return 0;
}

/** The efficient way.
 * When it comes to performance you cannot beat the classic C style operator[]
 * (pointer) access. Therefore, the most efficient method we can recommend
 * for making the assignment is:
 */
Mat& ScanImageAndReduceC(Mat& I, const uchar* const table) {
  // accept only char type matrices
  CV_Assert(I.depth() == CV_8U);
  int channels = I.channels();
  int nRows = I.row;
  int nCols = I.col;
  if (I.isContinuous()) {
    nCols *= nRows;
    nRows = 1;
  }
  int i, j;
  uchar* p;
  for (i = 0; i < nRows; ++i) {
    p = I.ptr<uchar>(i);
    for (j = 0; j < nCols; ++j) {
      p[j] = table[p[j]];
    }
  }
  return I;
}

// The iterator (safe) method
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table) {
  // accept only char type matrices
  CV_Assert(I.depth() == CV_8U);
  const int channels = I.channels();
  switch (channels) {
    case 1: {
      MatIterator_<uchar> it, end;
      for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
        *it = table[*it];
      break;
    }
    case 3: {
      MatIterator_<Vec3b> it, end;
      for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it) {
        (*it)[0] = table[(*it)[0]];
        (*it)[1] = table[(*it)[1]];
        (*it)[2] = table[(*it)[2]];
      }
    }
  }
  return I;
}

// On-the-fly address calculation with reference returning
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table) {
  // accept only char type matrices
  CV_Assert(I.depth() == CV_8U);
  const int channels = I.channels();
  switch (channels) {
    case 1: {
      for (int i = 0; i < I.rows; ++i)
        for (int j = 0; j < I.cols; ++j)
          I.at<uchar>(i, j) = table[I.at<uchar>(i, j)];
      break;
    }
    case 3: {
      Mat_<Vec3b> _I = I;
      for (int i = 0; i < I.rows; ++i)
        for (int j = 0; j < I.cols; ++j) {
          _I(i, j)[0] = table[_I(i, j)[0]];
          _I(i, j)[1] = table[_I(i, j)[1]];
          _I(i, j)[2] = table[_I(i, j)[2]];
        }
      I = _I;
      break;
    }
  }
  return I;
}

int main(int argc, char const* argv[]) {
  test_case();
  // ScanImageAndReduceC();
  // ScanImageAndReduceIterator();
  // ScanImageAndReduceRandomAccess();
  // The Core Function the very fast!
  /**
   * Mat lookUpTable(1, 256, CV_8U);
   * uchar* p = lookUpTable.ptr();
   * for (int i = 0; i < 256; ++i) p[i] = table[i];
   */
  return 0;
}
