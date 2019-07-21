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
}

int main(int argc, char const *argv[]) {
  test_case();
  return 0;
}
