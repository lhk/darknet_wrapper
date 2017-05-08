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

    // applying the detector to a file
    box** outboxes= new box*;
    float** outprobs= new float*;
    int** outclasses= new int*;
    int hits;
    char* filename="res/1.png";
    darknet.darknet_detect_file(filename, 0.5, &hits, outboxes, outprobs, outclasses);


    // loading an image and applying the detector to the loaded image
    Mat test_image=imread("res/1.png");
    if(!test_image.data){
        cout<<"couldn't load image"<<endl;
        return -1;
    }

    // in C, the Mat type is called IplImage. Thankfully, the conversion is quite simple
    // plus, darknet expects this IplImage to be in RGB format
    Mat rgb_image;
    cvtColor(test_image, rgb_image, COLOR_BGR2RGB);
    IplImage src=rgb_image;

    darknet.darknet_detect_img(&src, 0.5, &hits, outboxes, outprobs, outclasses);

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

