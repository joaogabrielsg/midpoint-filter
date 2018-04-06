#include <stdio.h>
#include <memory.h>
#include "image.h"


void midpoint(struct Image *IMAGE, struct Image *IMAGE1){
    int x, y, i, j, w, z, smin, smax, n;
    int a[3][3];
    n = 3;
    for(y=0; y < IMAGE->rows; y++){
        for(x=0; x < IMAGE->columns; x++){
            smin=255;
            smax=0;
//            printf("%d %d\n", x,y);
            for(j=-n/2; j<=n/2; j++){
                for(i=-n/2; i<=n/2; i++){
//
                    if((x+i) <= 0 || (x+i) > IMAGE->columns || (y+j) <= 0 || (y+j) > IMAGE->rows){
                        a[j+n/2][i+n/2] = -1;
                    }else{
                        a[j+n/2][i+n/2] = IMAGE->data[x+i+(long)(y+j) * IMAGE->columns];
                    }
                }
            }
            for(w=0; w<=n-1;w++){
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
            IMAGE1->data[x + (long) y * IMAGE->columns] = (smin + smax)/2;
            printf("%d\n", (smin + smax)/2);

        }
    }
}


int main()
{
    struct Image in,out;
    in.rows = out.rows = 96;
    in.columns = out.columns =  98;
    image_in(&in);
    midpoint(&in,&out);
    saveImg(&out);

    return 1;
}
