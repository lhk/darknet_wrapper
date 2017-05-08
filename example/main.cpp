#include "wrapper_cpp.h"

#include <iostream>

using namespace std;

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

    for(int i=0; i<hits; i++){
        box hitbox=(*outboxes)[i];

    }

	return 0;
}

