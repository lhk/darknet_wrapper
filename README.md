# This is a c++ wrapper for darknet

This wrapper compiles darknet as a shared library and offers a small interface to use it from c++.
Key features are integration with cmake and opencv.

# Structure
The wrapper is a c++ singleton.
To use darknet, you need to create an instance of type ´network´.
The struct ´network´ is defined in ´network.h´, which includes cuda source files.
It's not easily possible to import this header into c++ code.
The c++ compiler can work with regions marked as c code. 
But cuda within these c regions is tricky.
So I decided to keep the ´network´ struct invisible to the c++ code.
The library just creates a ´network´ object and exposes methods to work with it.
In the current implementation, just one such ´network´ object is allocated.
So I've created a singleton which can be used to request the object.

# Installation

1. clone this repo

2. install opencv

    The opencv installation can be quite painful.
    Janis Maczijewski created a great bashscript that will solve this problem for you.
    It installs opencv to /opt/opencv320.
    So the first step is to run
    ./install_opencv320.bash

    I would recommend using this script, even if you already have an existing opencv installation.
    We used this library while linking against opencv3.2.0, and didn't have any problems.
    
    If you want to use your own opencv version, you have to edit the Makefile in darknet/ and the CMakeLists.txt
    Look for /opt/opencv320 and replace it with your paths.

3. install cuda and cudnn

    Follow the nvidia instructions on how to install them
    
    You can compile darknet without cudnn.
    To do this, you need to edit the Makefile in darknet/
    At the very top, set CUDNN=0

4. clone the darknet repo

    Move out of this folder and execute
     - git clone https://github.com/pjreddie/darknet
     - git checkout 59ed1719d4aa77a462eb41dd4db2dd3a2f8e4a1b
    
    Then take all the darknet source files from darknet/src/ and copy them to darknet/src/ in this repo.
    Copy darknet/include to darknet/. Darknet/ now contains both src/ and include/
    You don't need any other files.

5. compile darknet

    in this repo, go to darknet/
    and run
     - make -j 8
    
    If there are any problems, try
     - make clean
     - make
    
    Without the -j 8 option, the compilation will use just one core.
    Multicore compilation can swallow error messages.


6. Compile the wrapper

     - mkdir build
     - cd build
     - cmake ..
     - make -j 8

7. run the wrapper
