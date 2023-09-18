
#include <math.h>

void simp1(a,mm,ll,nll,iabf,kp,bmax)
float **a,*bmax;
int *kp,iabf,ll[],mm,nll;
{
	int k;
	float test;

	if (nll <= 0)
		*bmax=0.0;
	else {
		*kp=ll[1];
		*bmax=a[mm+1][*kp+1];
		for (k=2;k<=nll;k++) {
			if (iabf == 0)
				test=a[mm+1][ll[k]+1]-(*bmax);
			else
				test=fabs(a[mm+1][ll[k]+1])-fabs(*bmax);
			if (test > 0.0) {
				*bmax=a[mm+1][ll[k]+1];
				*kp=ll[k];
			}
		}
	}
}
