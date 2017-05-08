#include "wrapper_cpp.h"

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Darknet darknet;

int main(int argc, char **argv)
{
    cout<<"main"<<endl;
    box test={1,2,3,4};

    char* cfgfile="res/cones.cfg";
    char* weightsfile="res/cones_final.weights";
    char* filename="res/1.png";

    box** outboxes= new box*;
    float** outprobs= new float*;
    int** outclasses= new int*;
    int hits;

    darknet.darknet_initialize();

    darknet.darknet_detect(cfgfile, weightsfile, filename, 0.5, &hits, outboxes, outprobs, outclasses);

    cout<<"hits: "<<hits<<endl;

    Mat test_image=imread("res/1.png");
    if(!test_image.data){
        cout<<"couldn't load image"<<endl;
        return -1;
    }

    cout<<"image dimensions:"<<endl;
    cout<<"x: "<<test_image.cols<<", y: "<<test_image.rows<<endl;

    for(int i=0; i<hits; i++){
        box hitbox=(*outboxes)[i];

        cout<<"hitbox number: "<<i<<endl;
        cout<<"x: "<<hitbox.x<<", y: "<<hitbox.y<<", w: "<<hitbox.w<<", h: "<<hitbox.h<<endl;

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

