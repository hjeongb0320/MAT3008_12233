
#include <math.h>
#include "nrutil.h"

void usrfun();
#define FREERETURN {free_matrix(fjac,1,n,1,n);free_vector(fvec,1,n);\
	free_vector(p,1,n);free_ivector(indx,1,n);return;}

void mnewt(ntrial,x,n,tolx,tolf)
float tolf,tolx,x[];
int n,ntrial;
{
	void lubksb(),ludcmp();
	int k,i,*indx;
	float errx,errf,d,*fvec,**fjac,*p;

	indx=ivector(1,n);
	p=vector(1,n);
	fvec=vector(1,n);
	fjac=matrix(1,n,1,n);
	for (k=1;k<=ntrial;k++) {
		usrfun(x,n,fvec,fjac);
		errf=0.0;
		for (i=1;i<=n;i++) errf += fabs(fvec[i]);
		if (errf <= tolf) FREERETURN
		for (i=1;i<=n;i++) p[i] = -fvec[i];
		ludcmp(fjac,n,indx,&d);
		lubksb(fjac,n,indx,p);
		errx=0.0;
		for (i=1;i<=n;i++) {
			errx += fabs(p[i]);
			x[i] += p[i];
		}
		if (errx <= tolx) FREERETURN
	}
	FREERETURN
}
#undef FREERETURN
