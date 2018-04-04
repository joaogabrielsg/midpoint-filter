#include <stdio.h>
#include <memory.h>
#include "image.h"

void midpoint(struct Image *IMAGE){
    int x, y, i, j, smin, smax, n;
    int a[5][5];
    n = 5;
    
    for(y=0; y < IMAGE->rows; y++){
        for(x=0; x < IMAGE->columns; x++){
            smin=255;
            smax=0;
            for(j=-n/2; j<=n/2; j++){
                for(i=-n/2; i<=n/2; i++){
                    if((x+i) < 0 || (x+i) > IMAGE->columns || (y+j) < 0 || (y+j) > IMAGE->rows){
                        a[j+n/2][i+n/2] = -1;
                    }else{
                        a[j+n/2][i+n/2] = IMAGE->data[x+i+(long)(y+j) * IMAGE->columns];
                    }
                }
            }
            for(j=0; j<=n-1;j++){
                for(i=0; i<=n-1; i++){
                    if(a[j][i] < smin && a[j][i] >= 0){
                        smin = a[j][i];
                    }
                    if(a[j][i] > smax && a[j][i] >= 0){
                        if (a[j][i] > 255) {
                            smax = 255;
                        }else{
                            smax = a[j][i];
                        }
                    }
                }
            }
            IMAGE->data[x + (long) y * IMAGE->columns] = (smin + smax)/2;
        }
    }
}

int main()
{
    struct Image image;
    
    image_in(&image);
    midpoint(&image);
    saveImg(&image);
    
    return 1;
}