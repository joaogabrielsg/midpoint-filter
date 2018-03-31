#include <stdio.h>
#include <stdlib.h>
#include "image.h"
void image_in(struct Image *IMAGE){
    FILE *file;
    int i;

    file = fopen("teste.bmp", "rb");

    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }

    for(i=0; i<IMAGE->columns; i++){
        fread(IMAGE->data + i*IMAGE->columns, IMAGE->columns, 1, file);
        printf("Image in\n");
        printf("%d\n",&IMAGE->columns);
    }

    fclose(file);
}


void image_out(struct Image *IMAGE){
    FILE *file;
    int i;
    file = fopen("out_teste.bmp", "wb");

    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de escrita \n");
    }

    for(i=0; i<IMAGE->columns; i++){
        fwrite(IMAGE->data + i*IMAGE->columns, IMAGE->columns, 1, file);
        printf("Image out \n");
        printf("%d\n",&IMAGE->columns);

    }

    fclose(file);
}
