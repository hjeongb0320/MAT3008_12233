
#include <math.h>
#include "nrutil.h"

extern long idum;
extern float tt;

float amotsa(p,y,psum,ndim,pb,yb,funk,ihi,yhi,fac)
float (*funk)(),**p,*yb,*yhi,fac,pb[],psum[],y[];
int ihi,ndim;
{
	float ran1();
	int j;
	float fac1,fac2,yflu,ytry,*ptry;

	ptry=vector(1,ndim);
	fac1=(1.0-fac)/ndim;
	fac2=fac1-fac;
	for (j=1;j<=ndim;j++)
		ptry[j]=psum[j]*fac1-p[ihi][j]*fac2;
	ytry=(*funk)(ptry);
	if (ytry <= *yb) {
		for (j=1;j<=ndim;j++) pb[j]=ptry[j];
		*yb=ytry;
	}
	yflu=ytry-tt*log(ran1(&idum));
	if (yflu < *yhi) {
		y[ihi]=ytry;
		*yhi=yflu;
		for (j=1;j<=ndim;j++) {
			psum[j] += ptry[j]-p[ihi][j];
			p[ihi][j]=ptry[j];
		}
	}
	free_vector(ptry,1,ndim);
	return yflu;
}
