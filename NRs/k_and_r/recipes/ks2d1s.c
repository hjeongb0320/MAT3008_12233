
#include <math.h>
#include "nrutil.h"

void ks2d1s(x1,y1,n1,quadvl,d1,prob)
float *d1,*prob,x1[],y1[];
unsigned long n1;
void (*quadvl)();
{
	float probks();
	void pearsn(),quadct();
	unsigned long j;
	float dum,dumm,fa,fb,fc,fd,ga,gb,gc,gd,r1,rr,sqen;

	*d1=0.0;
	for (j=1;j<=n1;j++) {
		quadct(x1[j],y1[j],x1,y1,n1,&fa,&fb,&fc,&fd);
		(*quadvl)(x1[j],y1[j],&ga,&gb,&gc,&gd);
		*d1=FMAX(*d1,fabs(fa-ga));
		*d1=FMAX(*d1,fabs(fb-gb));
		*d1=FMAX(*d1,fabs(fc-gc));
		*d1=FMAX(*d1,fabs(fd-gd));
	}
	pearsn(x1,y1,n1,&r1,&dum,&dumm);
	sqen=sqrt((double)n1);
	rr=sqrt(1.0-r1*r1);
	*prob=probks(*d1*sqen/(1.0+rr*(0.25-0.75/sqen)));
}
