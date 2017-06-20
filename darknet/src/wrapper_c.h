#ifndef WRAPPER_C
#define WRAPPER_C

#include "box.h"
#include "opencv2/imgproc/imgproc_c.h"
//#include "opencv2/core/version.hpp"

void setup_network(const char* cfgfile, const char* weightfile);

void setup_cuda();



void detect_file(char* filename, float thresh, int* hits,
            box** outboxes, float** outprobs, int** outclasses);

void detect_img(IplImage* src, float thresh, int* hits,
            box** outboxes, float** outprobs, int** outclasses);

void set_print_output(int value);

void cleanup();

#endif

