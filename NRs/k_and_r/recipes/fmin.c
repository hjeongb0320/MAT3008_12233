
#include "nrutil.h"

extern int nn;
extern float *fvec;
extern void (*nrfuncv)();

float fmin(x)
float x[];
{
	int i;
	float sum;

	(*nrfuncv)(nn,x,fvec);
	for (sum=0.0,i=1;i<=nn;i++) sum += SQR(fvec[i]);
	return 0.5*sum;
}
