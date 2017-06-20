#ifndef DARKNET_CPP
#define DARKNET_CPP

#include <opencv2/opencv.hpp>

extern "C" {
#include "../darknet/src/wrapper_c.h"
}

class Darknet {
public:

    static Darknet &getInstance(const char *cfgfile = 0, const char *weightfile = 0);


    void darknet_detect_file(char *filename, float thresh, int *hits,
                             box **outboxes, float **outprobs, int **outclasses);

    void darknet_detect_img(IplImage* src, float thresh, int *hits,
                            box **outboxes, float **outprobs, int **outclasses);

    Darknet(Darknet const &) = delete;

    void operator=(Darknet const &)  = delete;

    ~Darknet();

private:

    Darknet(const char *cfgfile, const char *weightfile);
};

#endif
