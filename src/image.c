#include <stdio.h>
#include <stdlib.h>

struct Image{
	int rows;
	int columns;
	unsigned char *data;
	unsigned char type;
}


void image_in(struct Image *IMAGE){
    FILE *file;
    int i;

    file = fopen("MYIMAGE.RAW", "rb");
    for(i=0; i<IMAGE->rows; i++){
        fread(IMAGE->data + i*IMAGE->columns, IMAGE->columns, 1, file);
    }

    fclose(file);
}


void image_out(struct Image *IMAGE){
    FILE *file;
    int i;

    file = fopen("OUTIMAGE.RAW", "rb");
    for(i=0; i<IMAGE->rows; i++){
        fwrite(IMAGE->data + i*IMAGE->columns, IMAGE->columns, 1, file);
    }

    fclose(file);
}