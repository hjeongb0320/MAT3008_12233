
#include "nrutil.h"

void polin2(x1a,x2a,ya,m,n,x1,x2,y,dy)
float **ya,*dy,*y,x1,x1a[],x2,x2a[];
int m,n;
{
	void polint();
	int j;
	float *ymtmp;

	ymtmp=vector(1,m);
	for (j=1;j<=m;j++) {
		polint(x2a,ya[j],n,x2,&ymtmp[j],dy);
	}
	polint(x1a,ymtmp,m,x1,y,dy);
	free_vector(ymtmp,1,m);
}
