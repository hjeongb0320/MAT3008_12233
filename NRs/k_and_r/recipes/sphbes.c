
#include <math.h>
#define RTPIO2 1.2533141

void sphbes(n,x,sj,sy,sjp,syp)
float *sj,*sjp,*sy,*syp,x;
int n;
{
	void bessjy();
	void nrerror();
	float factor,order,rj,rjp,ry,ryp;

	if (n < 0 || x <= 0.0) nrerror("bad arguments in sphbes");
	order=n+0.5;
	bessjy(x,order,&rj,&ry,&rjp,&ryp);
	factor=RTPIO2/sqrt(x);
	*sj=factor*rj;
	*sy=factor*ry;
	*sjp=factor*rjp-(*sj)/(2.0*x);
	*syp=factor*ryp-(*sy)/(2.0*x);
}
#undef RTPIO2
