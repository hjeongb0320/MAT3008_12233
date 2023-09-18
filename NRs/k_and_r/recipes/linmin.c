
#include "nrutil.h"
#define TOL 2.0e-4

int ncom;
float *pcom,*xicom,(*nrfunc)();

void linmin(p,xi,n,fret,func)
float (*func)(),*fret,p[],xi[];
int n;
{
	float brent(),f1dim();
	void mnbrak();
	int j;
	float xx,xmin,fx,fb,fa,bx,ax;

	ncom=n;
	pcom=vector(1,n);
	xicom=vector(1,n);
	nrfunc=func;
	for (j=1;j<=n;j++) {
		pcom[j]=p[j];
		xicom[j]=xi[j];
	}
	ax=0.0;
	xx=1.0;
	mnbrak(&ax,&xx,&bx,&fa,&fx,&fb,f1dim);
	*fret=brent(ax,xx,bx,f1dim,TOL,&xmin);
	for (j=1;j<=n;j++) {
		xi[j] *= xmin;
		p[j] += xi[j];
	}
	free_vector(xicom,1,n);
	free_vector(pcom,1,n);
}
#undef TOL
