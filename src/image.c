
//
#include <stdio.h>
#include <stdlib.h>
#include "image.h"


void image_in(struct Image *IMAGE){
    FILE *file;
    int i, row, column, size, value;

    char type, file_name, some_thing;
    char teste[IMAGE->rows];
    file = fopen("teste_out.pgm", "r");
    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }

    fscanf(file, "%s\r\n", &type);
    printf("%s", &type);

    fscanf(file, "%s", &type);
    printf("%s", &type);

    fscanf(file, "%s", &type);
    printf("%s", &type);

    fscanf(file, "%s", &type);
    printf("%s", &type);

    fscanf(file, "%s\r\n", &type);
    printf("%s\n", &type);


    fscanf(file, "%d", &row);
    printf("%d ", row);

    fscanf(file, "%d", &column);
    printf("%d\n", column);

    fscanf(file, "%d", &size);
    printf("%d\n", size);


    for(i=0; i<(row*column); i++){
        fscanf(file, "%d", &value);
        IMAGE->data[i] = value;
    }

    fclose(file);

}

void saveImg(struct Image *image)
{
    int i,j, chars = 0;
    FILE *arq;    //ponteiro para arquivo de saída

    arq = fopen("out_teste.ascii.pgm","w");
    if (arq == NULL) {
        printf("Não criou o arquivo de saida");
    }

    fprintf(arq,"P2\n");
    fprintf(arq, "# Created by IrfanView created by PGMA_IO::PGMA_WRITE.\n");
    fprintf(arq,"%d  %d\n",96,98) ; //cabeçalho do arquivo de saída
    fprintf(arq,"%d\n",255);

    int line = 0;

    for (i=1; i<(9408); i++){

        if (line == 511) {
            fprintf(arq, "\n");
            line = 0;
        }
        //printf("%d\n", i);
        //            printf("%d", image->data[i*j]);
        //            fprintf(arq, "%d ", image->data[i * j]);
        chars++;
        if (chars == 12) {
            fprintf(arq, "%d \n", image->data[i]);
            chars = 0;
        }else{
            fprintf(arq, "%d  ", image->data[i]);
        }
        line++;
    }



//    for(i=1; i <= 512; i++)
//    {
//        for(j=1; j <= 512; j++)
//        {
//            printf("%d\n", ((i * j) - 1));
////            printf("%d", image->data[i*j]);
////            fprintf(arq, "%d ", image->data[i * j]);
//            chars++;
//            if (chars == 12) {
//                fprintf(arq, "%d \n", image->data[(i * j) - 1]);
//                chars = 0;
//            }else{
//                fprintf(arq, "%d  ", image->data[(i * j) - 1]);
//            }
//        }
//        fprintf(arq, "\n");
//    }
    fclose(arq);
}


void image_out(struct Image *IMAGE){
    FILE *file,*file2;
    int i, row, column, size, value = 0,cont = 0;

    char type, file_name;
    char teste;
    file = fopen("out_teste.ascii.pgm", "wb");
    file2 = fopen("image001.pgm", "rb");

    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }

    fscanf(file2, "%s", &type);
    printf("%s", &type);
    fprintf(file,"%s\r\n",&type);


    fscanf(file2, "%s", &file_name);
    printf("%s", &file_name);
    fprintf(file,"%s ",&file_name);


    fscanf(file2, "%s", &file_name);
    printf("%s", &file_name);
    fprintf(file,"%s ",&file_name);


    fscanf(file2, "%s", &file_name);
    printf("%s", &file_name);
    fprintf(file,"%s ",&file_name);


    fscanf(file2, "%s", &file_name);
    printf("%s", &file_name);
    fprintf(file,"%s",&file_name);


    fscanf(file2, "%d", &row);
    printf("%d \n", row);
    fprintf(file,"%d ",row);


    fscanf(file2, "%d", &column);
    printf("%d\n", column);
    fprintf(file,"%d\r\n",column);

    fscanf(file2, " %d", &size);
    printf("%d\n", size);
    fprintf(file,"%d\r\n",size);



    for(i=0; i<(row * column); i++){
        if(cont < 16)
        {
//            value = IMAGE->data;
            fprintf(file,"%d ",value);
            cont++;
        }
        else{
            IMAGE->data[i] = value;
            fprintf(file,"%d \r\n",value);
            cont=0;

        }
    }

    fclose(file);
    fclose(file2);

}

