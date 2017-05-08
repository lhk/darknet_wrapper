#include "wrapper_cpp.h"

Darknet::Darknet() {

}

Darknet::~Darknet() {

}

void Darknet::darknet_detect(char *filename, float thresh, int* hits, box **outboxes,
                             float **outprobs, int **outclasses) {

    detect(filename, thresh, hits, outboxes, outprobs, outclasses);
}

void Darknet::darknet_setup_cuda() {
    setup_cuda();
}

void Darknet::darknet_setup_network(char *cfgfile, char *weightfile) {
    setup_network(cfgfile, weightfile);
}