
#include <math.h>
#include "nrutil.h"

void ks2d2s(x1,y1,n1,x2,y2,n2,d,prob)
float *d,*prob,x1[],x2[],y1[],y2[];
unsigned long n1,n2;
{
	float probks();
	void pearsn(),quadct();
	unsigned long j;
	float d1,d2,dum,dumm,fa,fb,fc,fd,ga,gb,gc,gd,r1,r2,rr,sqen;

	d1=0.0;
	for (j=1;j<=n1;j++) {
		quadct(x1[j],y1[j],x1,y1,n1,&fa,&fb,&fc,&fd);
		quadct(x1[j],y1[j],x2,y2,n2,&ga,&gb,&gc,&gd);
		d1=FMAX(d1,fabs(fa-ga));
		d1=FMAX(d1,fabs(fb-gb));
		d1=FMAX(d1,fabs(fc-gc));
		d1=FMAX(d1,fabs(fd-gd));
	}
	d2=0.0;
	for (j=1;j<=n2;j++) {
		quadct(x2[j],y2[j],x1,y1,n1,&fa,&fb,&fc,&fd);
		quadct(x2[j],y2[j],x2,y2,n2,&ga,&gb,&gc,&gd);
		d2=FMAX(d2,fabs(fa-ga));
		d2=FMAX(d2,fabs(fb-gb));
		d2=FMAX(d2,fabs(fc-gc));
		d2=FMAX(d2,fabs(fd-gd));
	}
	*d=0.5*(d1+d2);
	sqen=sqrt(n1*n2/(double)(n1+n2));
	pearsn(x1,y1,n1,&r1,&dum,&dumm);
	pearsn(x2,y2,n2,&r2,&dum,&dumm);
	rr=sqrt(1.0-0.5*(r1*r1+r2*r2));
	*prob=probks(*d*sqen/(1.0+rr*(0.25-0.75/sqen)));
}
