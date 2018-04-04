#include <stdio.h>
#include <stdlib.h>
#include "image.h"


void image_in(struct Image *image){
    FILE *file;
    int i, row, column, size, value;
    
    char file_name;
    file = fopen("baboon.ascii.pgm", "rb");
    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }
    
    fscanf(file, "%s", &image->type);
    fscanf(file, "%s", &file_name);
    fscanf(file, "%s", &file_name);
    fscanf(file, "%s", &file_name);
    fscanf(file, "%s", &file_name);
    fscanf(file, "%s", &file_name);
    fscanf(file, "%d", &image->rows);
    fscanf(file, "%d", &image->columns);
    fscanf(file, "%d", &image->max_size);
    
    
    for(i=0; i<=(image->rows * image->columns); i++){
        fscanf(file, "%d", &image->data[i]);
    }
    fclose(file);
}

void saveImg(struct Image *image)
{
    int i, chars = 0, line = 0;
    FILE *arq;    //ponteiro para arquivo de saída
    
    arq = fopen("out_teste.ascii.pgm","w");
    if (arq == NULL) {
        printf("Não criou o arquivo de saida");
    }
    
    fprintf(arq,"P2\n");
    fprintf(arq, "# baboon.pgma created by PGMA_IO::PGMA_WRITE.\n");
    fprintf(arq,"%d  %d\n",image->rows,image->columns) ; //cabeçalho do arquivo de saída
    fprintf(arq,"%d\n",image->max_size);
    
    for (i=1; i<(image->columns*image->rows); i++){
        
        if (line == image->rows) {
            fprintf(arq, "\n");
            line = 0;
        }
        chars++;
        if (chars == 12) {
            fprintf(arq, "%d \n", image->data[i]);
            chars = 0;
        }else{
            fprintf(arq, "%d  ", image->data[i]);
        }
        line++;
    }
    fclose(arq);
}