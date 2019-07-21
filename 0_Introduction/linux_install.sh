# The packages can be installed using a terminal and the following commands or by using Synaptic Manager:

# [compiler] 
sudo apt-get install build-essential
# [required] 
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
# [optional] 
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

# Getting the Cutting-edge OpenCV from the Git Repository
cd ~/
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git

# 1. Create a temporary directory, which we denote as <cmake_build_dir>, where you want to put the generated Makefiles, project files as well the object files and output binaries and enter there.
cd ~/opencv
mkdir build
cd build

# 2.Configuring. Run cmake [<some optional parameters>] <path to the OpenCV source directory>
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..

# 3.From build directory execute make, it is recommended to do this in several threads.
make -j8

# 4.Building documents.
make install

# Done!