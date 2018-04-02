
#include <stdio.h>
#include <memory.h>
#include "image.h"


void midpoint(struct Image *IMAGE, struct Image *IMAGE1){
    int x, y, i, j, smin, smax, n;
    int a[11][11];
    n = 1;
    
    for(y=0; y<IMAGE->rows-n/2; y++){
        for(x=0; x<IMAGE->columns-n/2; x++){
            smin=255;
            smax=0;
            for(j=-n/2; j<=n/2; j++){
                for(i=-n/2; i<=n/2; i++){
//                    a[i+n/2][j+n/2]= *(IMAGE->data+x+i+(long)(y+j) * IMAGE->columns);
                    if(j < 0 || j > IMAGE->rows || i < 0 || i > IMAGE->columns){
                        a[i+n/2][j+n/2] = -1;
                    }else{
                        a[i+n/2][j+n/2] = IMAGE->data[x+i+(long)(y+j) * IMAGE->columns];
                    }
                }
            }
            for(j=0; j<=n-1;j++){
                for(i=0; i<=n-1; i++){
                    if(a[i][j] < smin && a[i][j] > 0){
                        smin = a[i][j];
                    }
                }
            }
            for(j=0; j<=n-1;j++){
                for(i=0; i<=n-1; i++){
                    if(a[i][j] > smax && a[i][j] > 0){
                        smax = a[i][j];
                    }
                }
            }
//            *(IMAGE1->data + x +(long) y *IMAGE->columns) = (smin + smax)/2;
            IMAGE1->data[x + (long) y * IMAGE->columns] = (smin + smax)/2;
            printf("%d\n", (smin + smax)/2);
            
        }
    }
}

int main()
{
    struct Image in,out;
    char teste;
    
    in.rows = out.rows = 191;
    in.columns = out.columns = 196;
//    in.type = out.type = BASIC;
//    in.data = (unsigned char *)calloc(in.rows,in.columns);
//    out.data = (unsigned char *)calloc(out.rows,out.columns);
    //out.data = (unsigned char *)calloc((out.rows*out.columns),sizeof(unsigned char));
    
    image_in(&in);
//    teste = *(in.data +(0*in.columns)+2);
//    printf("%c",teste);
     midpoint(&in,&out);
    //image_out(&out);
//    printf("%d\n",out.data);
    
    return 1;
}

