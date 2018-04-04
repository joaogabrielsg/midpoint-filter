
//
#ifndef  IMAGE_H
#define  IMAGE_H

#include <stdio.h>
#include <stdlib.h>

struct Image{
    int rows;
    int columns;
    int data[262144];
    unsigned char type;
};
void image_in(struct Image *IMAGE);
void image_out(struct Image *IMAGE);
void saveImg(struct Image *image);
#define BASIC 0
#define UINT 1
#endif  /*IMAGE_H*/
