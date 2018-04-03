#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void image_in(struct Image *IMAGE){
    FILE *file;
<<<<<<< HEAD
    int i, row, column, size, value;

    char type, file_name;
=======
    int i, value;
>>>>>>> 8f67a6c0f544463a5005b9b9840526c2e02d8e00
    char teste[IMAGE->rows];
    file = fopen("balloons.ascii.pgm", "rb");
    if (file == NULL) {
        printf("Erro na abertura do arquivo de imagem de leitura \n");
    }
<<<<<<< HEAD

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

=======
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
    
    
>>>>>>> 8f67a6c0f544463a5005b9b9840526c2e02d8e00
}


void image_out(struct Image *IMAGE){
<<<<<<< HEAD
    FILE *file,*file2;
    int i, row, column, size, value,cont = 0;

    char type, file_name;
    char teste;
    file = fopen("out_teste.pgm", "wb");
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

=======
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
>>>>>>> 8f67a6c0f544463a5005b9b9840526c2e02d8e00
}
