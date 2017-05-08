#ifndef WRAPPER_C
#define WRAPPER_C

#include "box.h"

void setup_network(char* cfgfile, char* weightfile);

void setup_cuda();

void detect_file(char* filename, float thresh, int* hits,
                 box** outboxes, float** outprobs, int** outclasses);

void detect_img(void* filename, float thresh, int* hits,
                box** outboxes, float** outprobs, int** outclasses);

#endif

