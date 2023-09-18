
#include "nrutil.h"

void splin2(x1a,x2a,ya,y2a,m,n,x1,x2,y)
float **y2a,**ya,*y,x1,x1a[],x2,x2a[];
int m,n;
{
	void spline(),splint();
	int j;
	float *ytmp,*yytmp;

	ytmp=vector(1,m);
	yytmp=vector(1,m);
	for (j=1;j<=m;j++)
		splint(x2a,ya[j],y2a[j],n,x2,&yytmp[j]);
	spline(x1a,yytmp,m,1.0e30,1.0e30,ytmp);
	splint(x1a,yytmp,ytmp,m,x1,y);
	free_vector(yytmp,1,m);
	free_vector(ytmp,1,m);
}
