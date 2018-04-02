#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void image_in(struct Image *IMAGE){
    FILE *file;
    int i, value;
    char teste[IMAGE->rows];
    file = fopen("MYIMAGE.txt", "rb");
    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }
    for(i=0; i<(IMAGE->rows * IMAGE->columns); i++){
        
        fscanf(file, "%d", &value);
        IMAGE->data[i] = value;

//        printf("%d \n", value);
//        teste[i] = IMAGE->data;
        //IMAGE->data = fgets(IMAGE->data,IMAGE->rows,file);
        /*if(IMAGE->data)
         {
         //printf("%c",IMAGE->data);
         }*/
        //printf("%c",teste[i]);
        
    }
//    IMAGE->data = teste;
    fclose(file);
    
    
}


void image_out(struct Image *IMAGE){
//    FILE *file;
//    int i;
//    file = fopen("out_teste.txt", "wb");
//    
//    if (file == NULL) {
//        printf("Erro na abertura do arquivo de imagem de escrita \n");
//    }
//    
//    for(i=0; i<IMAGE->rows; i++){
//        IMAGE->data = fgets(IMAGE->data,IMAGE->rows,file);
//        if(IMAGE->data)
//        {
//            fputs(IMAGE->data,file);
//        }
//        
//        
//        
//        //fwrite(IMAGE->data + i*IMAGE->columns, IMAGE->columns,1, file);
//        //printf("Image out \n");
//        //printf("%d\n",&IMAGE->columns);
//        
//    }
//    
//    fclose(file);
}
