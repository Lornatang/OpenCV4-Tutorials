#include <iostream>
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

static void help(char* progName) {
  cout << endl
       << "This program shows how to filter images with mask: the write it "
       << "yourself and the"
       << "filter2d way. " << endl
       << "Usage:" << endl
       << progName
       << " [image_path -- default ../images/demo1.png] [G -- grayscale] "
       << endl
       << endl;
}

void Sharpen(const Mat& inputImg, Mat& result);

int main(int argc, char* argv[]) {
  help(argv[0]);
  const char* filename = argc >= 2 ? argv[1] : "../images/demo1.png";
  Mat src, dst0, dst1;
  if (argc >= 3 && !strcmp("G", argv[2]))
    src = imread(filename, IMREAD_GRAYSCALE);
  else
    src = imread(filename, IMREAD_COLOR);
  if (src.empty()) {
    cerr << "Can't open image [" << filename << "]" << endl;
    return -1;
  }

  namedWindow("Input", WINDOW_AUTOSIZE);
  namedWindow("Output", WINDOW_AUTOSIZE);

  imshow("Input", src);
  double t = (double)getTickCount();
  Sharpen(src, dst0);
  t = ((double)getTickCount() - t) / getTickFrequency();
  cout << "Hand written function time passed in seconds: " << t << endl;
  imshow("Output", dst0);
  waitKey();
  Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
  t = (double)getTickCount();
  filter2D(src, dst1, src.depth(), kernel);
  t = ((double)getTickCount() - t) / getTickFrequency();
  cout << "Built-in filter2D time passed in seconds:     " << t << endl;
  imshow("Output", dst1);
  waitKey();
  return 0;
}

// Mask operations on matrices are quite simple.
void Sharpen(const Mat& inputImg, Mat& result) {
  CV_Assert(inputImg.depth() == CV_8U);  // accept only uchar images
  const int nChannels = inputImg.channels();
  result.create(inputImg.size(), inputImg.type());
  for (int j = 1; j < inputImg.rows - 1; ++j) {
    const uchar* previous = inputImg.ptr<uchar>(j - 1);
    const uchar* current = inputImg.ptr<uchar>(j);
    const uchar* next = inputImg.ptr<uchar>(j + 1);
    uchar* output = result.ptr<uchar>(j);
    for (int i = nChannels; i < nChannels * (inputImg.cols - 1); ++i) {
      *output++ =
          saturate_cast<uchar>(5 * current[i] - current[i - nChannels] -
                               current[i + nChannels] - previous[i] - next[i]);
    }
  }
  result.row(0).setTo(Scalar(0));
  result.row(result.rows - 1).setTo(Scalar(0));
  result.col(0).setTo(Scalar(0));
  result.col(result.cols - 1).setTo(Scalar(0));
}
