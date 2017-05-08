#include "wrapper_cpp.h"

Darknet::Darknet() {

}

Darknet::~Darknet() {

}

void Darknet::darknet_detect(char *cfgfile, char *weightfile, char *filename, float thresh, int* hits, box **outboxes,
                             float **outprobs, int **outclasses) {

    detect(cfgfile, weightfile, filename, thresh, hits, outboxes,
            outprobs, outclasses);
}

void Darknet::darknet_initialize() {
    initialize();
}