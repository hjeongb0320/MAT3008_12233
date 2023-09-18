
#include "nrutil.h"
#define EPS 1.0e-6

extern int nvar;
extern float x1,x2;

int kmax,kount;
float *xp,**yp,dxsav;

void shoot(n,v,f)
float f[],v[];
int n;
{
	void derivs(),load(),odeint(),rkqs(),score();
	int nbad,nok;
	float h1,hmin=0.0,*y;

	y=vector(1,nvar);
	kmax=0;
	h1=(x2-x1)/100.0;
	load(x1,v,y);
	odeint(y,nvar,x1,x2,EPS,h1,hmin,&nok,&nbad,derivs,rkqs);
	score(x2,y,f);
	free_vector(y,1,nvar);
}
#undef EPS
