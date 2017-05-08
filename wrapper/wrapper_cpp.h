#ifndef DARKNET_CPP
#define DARKNET_CPP

extern "C" {
#include "wrapper_c.h"
}

class Darknet
{
public:

    Darknet();
    ~Darknet();
    void darknet_detect(char* cfgfile, char* weightfile, char* filename, float thresh, int* hits,
                           box** outboxes, float** outprobs, int** outclasses);

    void darknet_initialize();
};

#endif
