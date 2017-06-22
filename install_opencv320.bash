# Janis' opencv installation script

set -e # exit if any command fails

if [ -d "/opt/opencv320" ]; then
    echo "Error: Directory /opt/opencv320 already exists."
    exit
fi

sudo mkdir /opt/opencv320

mkdir /tmp/opencvbuild320

cd /tmp/opencvbuild320
git clone https://github.com/opencv/opencv.git
cd /tmp/opencvbuild320/opencv
git checkout 3.2.0


cd /tmp/opencvbuild320
git clone https://github.com/opencv/opencv_contrib.git
cd /tmp/opencvbuild320/opencv_contrib
git checkout 3.2.0


cd /tmp/opencvbuild320/opencv
mkdir build
cd build

cmake -D WITH_CUDA=ON -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/opt/opencv320 -D BUILD_EXAMPLES=ON -D CUDA_GENERATION=Auto -DOPENCV_EXTRA_MODULES_PATH=/tmp/opencvbuild320/opencv_contrib/modules ..


read -p "Please check the cmake output. [Y] to continue: " -n 1 -r
echo  # new line
if [[ $REPLY =~ ^[Yy]$ ]]
then
    make -j8
    sudo make -j8 install
    rm -rf /tmp/opencvbuild320
fi
