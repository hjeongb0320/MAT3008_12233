
#include <math.h>
#include "nrutil.h"

void polcof(xa,ya,n,cof)
float cof[],xa[],ya[];
int n;
{
	void polint();
	int k,j,i;
	float xmin,dy,*x,*y;

	x=vector(0,n);
	y=vector(0,n);
	for (j=0;j<=n;j++) {
		x[j]=xa[j];
		y[j]=ya[j];
	}
	for (j=0;j<=n;j++) {
		polint(x-1,y-1,n+1-j,0.0,&cof[j],&dy);
		xmin=1.0e38;
		k = -1;
		for (i=0;i<=n-j;i++) {
			if (fabs(x[i]) < xmin) {
				xmin=fabs(x[i]);
				k=i;
			}
			if (x[i]) y[i]=(y[i]-cof[j])/x[i];
		}
		for (i=k+1;i<=n-j;i++) {
			y[i-1]=y[i];
			x[i-1]=x[i];
		}
	}
	free_vector(y,0,n);
	free_vector(x,0,n);
}
