
#include <math.h>
#include "nrutil.h"

void ksone(data,n,func,d,prob)
float (*func)(),*d,*prob,data[];
unsigned long n;
{
	float probks();
	void sort();
	unsigned long j;
	float dt,en,ff,fn,fo=0.0;

	sort(n,data);
	en=n;
	*d=0.0;
	for (j=1;j<=n;j++) {
		fn=j/en;
		ff=(*func)(data[j]);
		dt=FMAX(fabs(fo-ff),fabs(fn-ff));
		if (dt > *d) *d=dt;
		fo=fn;
	}
	en=sqrt(en);
	*prob=probks((en+0.12+0.11/en)*(*d));
}
