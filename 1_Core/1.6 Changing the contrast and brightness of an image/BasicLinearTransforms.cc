#include <iostream>
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgcodecs.hpp"

// we're NOT "using namespace std;" here, to avoid collisions between the beta
// variable and std::beta in c++17
using std::cin;
using std::cout;
using std::endl;

using namespace cv;

int main(int argc, char** argv) {
  CommandLineParser parser(argc, argv,
                           "{@input | ../images/demo2.png | input image}");
  Mat image = imread(parser.get<String>("@input"));
  if (image.empty()) {
    cout << "Could not open or find the image!\n" << endl;
    cout << "Usage: " << argv[0] << " <Input image>" << endl;
    return -1;
  }
  Mat new_image = Mat::zeros(image.size(), image.type());
  double alpha = 1.0; /*< Simple contrast control */
  int beta = 0;       /*< Simple brightness control */
  cout << " Basic Linear Transforms " << endl;
  cout << "-------------------------" << endl;
  cout << "* Enter the alpha value [1.0-3.0]: ";
  cin >> alpha;
  cout << "* Enter the beta value [0-100]: ";
  cin >> beta;
  for (int y = 0; y < image.rows; y++) {
    for (int x = 0; x < image.cols; x++) {
      for (int c = 0; c < image.channels(); c++) {
        new_image.at<Vec3b>(y, x)[c] =
            saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
      }
    }
  }
  imshow("Original Image", image);
  imshow("New Image", new_image);
  waitKey();
  return 0;
}