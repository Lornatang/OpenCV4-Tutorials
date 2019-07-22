#include <iostream>
#include "opencv4/opencv2/core.hpp"
#include "opencv4/opencv2/opencv.hpp"

using namespace cv;
using namespace std;

// Input/Output
// void io {
//   const char* filename_rgb = "../images/demo1_bgr.png";
//   Mat img = imread(filename);
//   imwrite(filename, img);

//   const char* filename_gray = "../images/demo1_gray.png";
//   Mat img = imread(filename, IMREAD_GRAYSCALE);
//   imwrite(filename, img);
// }

// // Basic operations with images
// void imgOperation() {
//   const char* filename = "../images/demo1.png";

//   Mat img1 = imread(filename);

//   Scalar intensity = img.at<uchar>(y, x);
//   Scalar intensity = img.at<uchar>(Point(x, y));

//   Vec3b intensity = img.at<Vec3b>(y, x);
//   uchar blue = intensity.val[0];
//   uchar green = intensity.val[1];
//   uchar red = intensity.val[2];

//   // Memory management and reference counting
//   Mat img2 = imread(filename);
//   Mat img3 = img2.clone();

//   Mat img4 = imread(filename);
//   Mat sobelx;
//   Sobel(img4, sobelx, CV_32F, 1, 0);
//   namedWindow("Sobel", WINDOW_AUTOSIZE);
//   imshow("Sobel", sobelx);
//   waitKey();
// }

void visualImg() {
  Mat img = imread("../images/demo1.png");
  Mat gray;
  Mat sobelx;
  Mat draw;
  double minVal, maxVal;
  cvtColor(img, gray, COLOR_BGR2GRAY);
  Sobel(gray, sobelx, CV_32F, 1, 0);
  minMaxLoc(sobelx, &minVal, &maxVal);  // find minimum and maximum intensities

  sobelx.convertTo(draw, CV_8U, 255.0 / (maxVal - minVal),
                   -minVal * 255.0 / (maxVal - minVal));
  namedWindow("image", WINDOW_AUTOSIZE);
  imshow("image", draw);
  waitKey();
}

int main(int argc, char const* argv[]) {
  // io();
  // imgOperation();
  visualImg();
  return 0;
}
