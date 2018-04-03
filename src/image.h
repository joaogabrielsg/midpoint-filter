#ifndef  IMAGE_H
#define  IMAGE_H

#include <stdio.h>
#include <stdlib.h>

struct Image{
    int rows;
    int columns;
<<<<<<< HEAD
    int data[307200];
=======
    int data[37436];
>>>>>>> 8f67a6c0f544463a5005b9b9840526c2e02d8e00
    unsigned char type;
};
void image_in(struct Image *IMAGE);
void image_out(struct Image *IMAGE);
#define BASIC 0
#define UINT 1
#endif  /*IMAGE_H*/
