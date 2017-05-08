#include "wrapper_cpp.h"

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Darknet darknet;

int main(int argc, char **argv)
{
    // setup the network.
    // you MUST NOT run this more than once
    char* cfgfile="res/cones.cfg";
    char* weightsfile="res/cones_final.weights";

    darknet.darknet_setup_network(cfgfile, weightsfile);
    darknet.darknet_setup_cuda();

    // applying the detector to an image
    box** outboxes= new box*;
    float** outprobs= new float*;
    int** outclasses= new int*;
    int hits;
    char* filename="res/1.png";
    darknet.darknet_detect(filename, 0.5, &hits, outboxes, outprobs, outclasses);

    Mat test_image=imread("res/1.png");
    if(!test_image.data){
        cout<<"couldn't load image"<<endl;
        return -1;
    }

    for(int i=0; i<hits; i++){
        box hitbox=(*outboxes)[i];

        float x,y,w,h;
        x=hitbox.x-hitbox.w/2;
        y=hitbox.y-hitbox.h/2;
        w=hitbox.w;
        h=hitbox.h;
        rectangle(test_image, {x,y,w,h}, {255,0,0}, 3);
    }

    Mat resized_image;
    resize(test_image, resized_image, {1000,1000});
    imshow("resized image", resized_image);
    waitKey(0);

	return 0;
}

