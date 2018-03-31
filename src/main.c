#include <stdio.h>
#include <memory.h>
#include "image.h"


int main()
{

	struct Image in,out;


	in.rows = out.rows = 243;
	in.columns = out.columns = 243;
	in.type = out.type = UINT;

	in.data = (unsigned char *)calloc(in.rows,in.columns);
	out.data = (unsigned char *)calloc(out.rows,out.columns);

	image_in(&in);
    //midpoint(&in,&out);
	image_out(&in);



	return 1;
}

void midpoint(struct Image *IMAGE, struct Image *IMAGE1){
	int x, y, i, j, smin, smax, n;
	int a[3][3];
	n =3;
	for(y=n/2; y<IMAGE->rows-n/2; y++){
		for(x=n/2; x<IMAGE->columns-n/2; x++){
			smin=255;
			smax=0;
			for(j=-n/2; j<n/2; i++){
				for(i=-n/2; i<n/2; j++){
					a[i+n/2][j+n/2]= *(IMAGE->data+x+i+(long)(y+j) * IMAGE->columns);
				}
			}
			for(j=0; j<=n-1;j++){
				for(i=0; i<=n-1; i++){
					if(a[i][j] <smin){
						smin = a[i][j];
					}
				}
			}
			for(j=0; j<=n-1;j++){
				for(i=0; i<=n-1; i++){
					if(a[i][j] > smax){
						smax = a[i][j];
					}
				}
			}
			*(IMAGE1->data + x +(long) y *IMAGE->columns) = (smin + smax)/2;
		}
	}
}
