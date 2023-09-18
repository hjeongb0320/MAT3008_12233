
#include "nrutil.h"

void stoerm(y,d2y,nv,xs,htot,nstep,yout,derivs)
float d2y[],htot,xs,y[],yout[];
int nstep,nv;
void (*derivs)();
{
	int i,n,neqns,nn;
	float h,h2,halfh,x,*ytemp;

	ytemp=vector(1,nv);
	h=htot/nstep;
	halfh=0.5*h;
	neqns=nv/2;
	for (i=1;i<=neqns;i++) {
		n=neqns+i;
		ytemp[i]=y[i]+(ytemp[n]=h*(y[n]+halfh*d2y[i]));
	}
	x=xs+h;
	(*derivs)(x,ytemp,yout);
	h2=h*h;
	for (nn=2;nn<=nstep;nn++) {
		for (i=1;i<=neqns;i++)
			ytemp[i] += (ytemp[(n=neqns+i)] += h2*yout[i]);
		x += h;
		(*derivs)(x,ytemp,yout);
	}
	for (i=1;i<=neqns;i++) {
		n=neqns+i;
		yout[n]=ytemp[n]/h+halfh*yout[i];
		yout[i]=ytemp[i];
	}
	free_vector(ytemp,1,nv);
}
