#include <stdio.h>
#include <stdlib.h>
#include "image.h"
void image_in(struct Image *IMAGE){
    FILE *file;
    int i;

    file = fopen("teste.bmp", "r");

    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }

    for(i=0; i<IMAGE->rows; i++){
        fread(IMAGE->data + i*IMAGE->rows, IMAGE->rows, 1, file);
    }

    fclose(file);
}


void image_out(struct Image *IMAGE){
    FILE *file;
    int i;

    file = fopen("out_teste.bmp", "w");

    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de escrita \n");
    }

    for(i=0; i<IMAGE->rows; i++){
        fwrite(IMAGE->data + i*IMAGE->rows, IMAGE->rows, 1, file);
    }

    fclose(file);
}
