#include <stdio.h>
#include <stdlib.h>
#include "image.h"


void image_in(struct Image *IMAGE){
    FILE *file;
    int i, row, column, size, value;
    
    char type, file_name;
    char teste[IMAGE->rows];
    file = fopen("balloons.ascii.pgm", "rb");
    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }
    
    fscanf(file, "%s", &type);
    printf("%s", &type);
    
    fscanf(file, "%s", &file_name);
    printf("%s", &file_name);
    
    fscanf(file, "%s", &file_name);
    printf("%s", &file_name);
    
    fscanf(file, "%s", &file_name);
    printf("%s", &file_name);
    
    fscanf(file, "%s", &file_name);
    printf("%s", &file_name);
    
    fscanf(file, "%s", &file_name);
    printf("%s\n", &file_name);
    
    fscanf(file, "%d", &row);
    printf("%d \n", row);
    
    fscanf(file, "%d", &column);
    printf("%d\n", column);
    
    fscanf(file, "%d", &size);
    printf("%d\n", size);
    
    
    for(i=0; i<(row * column); i++){
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
    fprintf(arq, "# created by 'xv balloons_bw.tif'\n");
    fprintf(arq,"%d %d\n",640,480) ; //cabeçalho do arquivo de saída
    fprintf(arq,"%d\n",255);
    
    for(i=1; i <= 640; i++)
    {
        for(j=1; j <= 480; j++)
        {
            fprintf(arq, "%3d ", image->data[i * j]);
            chars++;
            if (chars == 17) {
                fprintf(arq, "\n");
                chars = 0;
            }
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
}


void image_out(struct Image *IMAGE){
    FILE *file,*file2;
    int i, row, column, size, value,cont = 0;
    
    char type, file_name;
    char teste;
    file = fopen("out_teste.ascii.pgm", "wb");
    file2 = fopen("balloons.ascii.pgm", "rb");
    
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
    
    fscanf(file2, "%s", &teste);
    printf("%s", &teste);
    fprintf(file,"%s\r\n",&teste);
    
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
            // value = IMAGE->data;
            fprintf(file,"%d ",value);
            cont++;
        }
        else{IMAGE->data[i] = value;
            fprintf(file,"%d \r\n",value);
            cont=0;}
    }
    
    fclose(file);
    fclose(file2);
    
}

