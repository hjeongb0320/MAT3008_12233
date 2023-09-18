
#include <math.h>
#include "nrutil.h"
#define SAFETY 0.9
#define PGROW -0.2
#define PSHRNK -0.25
#define ERRCON 1.89e-4

void rkqs(y,dydx,n,x,htry,eps,yscal,hdid,hnext,derivs)
float *hdid,*hnext,*x,dydx[],eps,htry,y[],yscal[];
int n;
void (*derivs)();
{
	void rkck();
	int i;
	float errmax,h,htemp,xnew,*yerr,*ytemp;

	yerr=vector(1,n);
	ytemp=vector(1,n);
	h=htry;
	for (;;) {
		rkck(y,dydx,n,*x,h,ytemp,yerr,derivs);
		errmax=0.0;
		for (i=1;i<=n;i++) errmax=FMAX(errmax,fabs(yerr[i]/yscal[i]));
		errmax /= eps;
		if (errmax <= 1.0) break;
		htemp=SAFETY*h*pow(errmax,PSHRNK);
		h=(h >= 0.0 ? FMAX(htemp,0.1*h) : FMIN(htemp,0.1*h));
		xnew=(*x)+h;
		if (xnew == *x) nrerror("stepsize underflow in rkqs");
	}
	if (errmax > ERRCON) *hnext=SAFETY*h*pow(errmax,PGROW);
	else *hnext=5.0*h;
	*x += (*hdid=h);
	for (i=1;i<=n;i++) y[i]=ytemp[i];
	free_vector(ytemp,1,n);
	free_vector(yerr,1,n);
}
#undef SAFETY
#undef PGROW
#undef PSHRNK
#undef ERRCON
