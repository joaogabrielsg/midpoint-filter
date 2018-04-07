#include <stdio.h>
#include <memory.h>
#include "image.h"


void midpoint(struct Image *IMAGE, struct Image *IMAGE1){
    int x, y, i, j, w, z, smin, smax, n;
    int a[3][3];  //Tamanho da Máscara nesse caso a mascara tem tamanho 3x3
    n = 3;
    for(y=0; y < IMAGE->rows; y++){
        for(x=0; x < IMAGE->columns; x++){
            smin=255;  //Valor  Maximo que um pixel pode assumir
            smax=0;    ////Valor  Minimo que um pixel pode assumir
//            printf("%d %d\n", x,y);
            for(j=-n/2; j<=n/2; j++){
                for(i=-n/2; i<=n/2; i++){
//
                    if((x+i) <= 0 || (x+i) > IMAGE->columns || (y+j) <= 0 || (y+j) > IMAGE->rows){  //tratamento para pixels da borda setando os valores fora da imagem para -1
                        a[j+n/2][i+n/2] = -1; //se o valor estiver fora recebe o valor -1
                    }else{
                        a[j+n/2][i+n/2] = IMAGE->data[x+i+(long)(y+j) * IMAGE->columns]; //senão recebe o valor original do pixel
                    }
                }
            }
            for(w=0; w<=n-1;w++){      //loop que checa os valores de minimos e maximos da máscara
                for(z=0; z<=n-1; z++){
                    if(a[w][z] < smin && a[w][z] >= 0){
                        smin = a[w][z];
                    }
                    if(a[w][z] > smax && a[w][z] >= 0){
                        if (a[w][z] > 255) {
                            smax = 255;
                        }else{
                            smax = a[w][z];
                        }
                    }
                }
            }
            IMAGE1->data[x + (long) y * IMAGE->columns] = (smin + smax)/2; // atribiu o pixel a media dos valores de maximos e minimos encontrados pela máscara
            printf("%d\n", (smin + smax)/2);

        }
    }
}


int main()
{
    //criação da estrutura imagem
    struct Image in,out;
    in.rows = out.rows = 96;
    in.columns = out.columns =  98;
    image_in(&in); //Leitura de arquivos da imagem
    midpoint(&in,&out); //aplicação do filtro
    saveImg(&out); //escrita do resultado do filtro em um arquivo de saida

    return 1;
}
