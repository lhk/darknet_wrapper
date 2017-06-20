#include "wrapper_cpp.h"

Darknet& Darknet::getInstance(const char *cfgfile, const char *weightfile) {
    static Darknet instance(cfgfile, weightfile);
    return instance;
}

Darknet::Darknet(const char* cfgfile, const char* weightfile) {
    setup_network(cfgfile, weightfile);
    setup_cuda();
    set_print_output(0);
}

Darknet::~Darknet() {
    cleanup();
}

void Darknet::darknet_detect_file(char *filename, float thresh, int* hits, box **outboxes,
                             float **outprobs, int **outclasses) {

    detect_file(filename, thresh, hits, outboxes, outprobs, outclasses);
}

void Darknet::darknet_detect_img(IplImage* src, float thresh, int* hits, box **outboxes,
                                   float **outprobs, int **outclasses) {

    detect_img(src, thresh, hits, outboxes, outprobs, outclasses);
}