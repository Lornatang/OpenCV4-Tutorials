#include "opencv4/opencv2/opencv.hpp"

using namespace cv;
using namespace std;

// mat operator
void mat() {
  Mat A, C;  // creates just the header parts
  // here we'll know the method used (allocate matrix)
  A = imread("./images/Mat.png", IMREAD_COLOR);
  cv::Mat B(A);  // Use the copy constructor
  C = A;         // Assignment operator

  Mat D(A, Rect(10, 10, 100, 100));      // using a rectangle
  Mat E = A(Range::all(), Range(1, 3));  // using row and column boundaries

  Mat F = A.clone();
  Mat G;
  A.copyTo(G);

  imshow("A image", A);
  imshow("B image", B);
  imshow("C image", C);
  imshow("D image", D);
  imshow("E image", E);
  imshow("F image", F);
  imshow("G image", G);
}

// Creating a Mat object explicitly
void explicitly() {
  // cv::Mat::Mat Constructor
  Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
  cout << "M = " << endl << " " << M << endl << endl;

  // Use C/C++ arrays and initialize via constructor
  int sz[3] = {2, 2, 2};
  Mat L(3, sz, CV_8UC(1), Scalar::all(0));

  // cv::Mat::create function
  M.create(4, 4, CV_8UC(2));
  cout << "M = " << endl << M << endl << endl;

  // MATLAB style initializer: cv::Mat::zeros , cv::Mat::ones , cv::Mat::eye .
  // Specify size and data type to use:
  Mat E = Mat::eye(4, 4, CV_64F);
  cout << "eye = " << endl << E << endl << endl;
  Mat O = Mat::ones(2, 2, CV_32F);
  cout << "Ones = " << endl << O << endl << endl;
  Mat Z = Mat::zeros(3, 3, CV_8UC1);
  cout << "Zeros = " << endl << Z << endl << endl;

  // For small matrices you may use comma separated initializers or initializer
  // lists (C++11 support is required in the last case):
  Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
  cout << "C = " << endl << " " << C << endl << endl;
  C = (Mat_<double>({0, 1, 2, 3, 4, 5, 6, 7, 8})).reshape(3);
  cout << "C = " << endl << " " << C << endl << endl;

  // Create a new header for an existing Mat object and cv::Mat::clone or
  // cv::Mat::copyTo it.
  Mat RowClone = C.row(1).clone();
  cout << "RowClone = " << endl << " " << RowClone << endl << endl;

  // You can fill out a matrix with random values using the cv::randu()
  // function. You need to give the lower and upper value for the random values:
  Mat R = Mat(3, 2, CV_8UC3);
  randu(R, Scalar::all(0), Scalar::all(255));
  cout << "R = " << endl << " " << R << endl << endl;
}

// Output formatting
void formatPrint() {
  Mat R = Mat(3, 2, CV_8UC3);
  randu(R, Scalar::all(0), Scalar::all(255));
  // default
  cout << "R (default) = " << endl << R << endl << endl;
  // python
  cout << "R (python)  = " << endl
       << format(R, Formatter::FMT_PYTHON) << endl
       << endl;
  // csv
  cout << "R (csv)     = " << endl
       << format(R, Formatter::FMT_CSV) << endl
       << endl;
  // numpy
  cout << "R (numpy)   = " << endl
       << format(R, Formatter::FMT_NUMPY) << endl
       << endl;
  // c
  cout << "R (c)       = " << endl
       << format(R, Formatter::FMT_C) << endl
       << endl;
  /* Output of other common items */
  // OpenCV offers support for output of other common OpenCV data structures too
  // via the << operator:
  // 2D Point
  Point2f P(5, 1);
  cout << "Point (2D) = " << P << endl << endl;
  // 3D Point
  Point3f P3f(2, 6, 7);
  cout << "Point (3D) = " << P3f << endl << endl;
  // std::vector via cv::Mat
  vector<float> v;
  v.push_back((float)CV_PI);
  v.push_back(2);
  v.push_back(3.01f);
  cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;
  // std::vector of points
  vector<Point2f> vPoints(20);
  for (size_t i = 0; i < vPoints.size(); ++i)
    vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
  cout << "A vector of 2D Points = " << vPoints << endl << endl;
}

int main(int argc, char const *argv[]) {
  mat();
  explicitly();
  formatPrint();
  return 0;
}
