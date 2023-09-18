
#include <math.h>
#include "nrutil.h"

void qrupdt(r,qt,n,u,v)
float **qt,**r,u[],v[];
int n;
{
	void rotate();
	int i,j,k;

	for (k=n;k>=1;k--) {
		if (u[k]) break;
	}
	if (k < 1) k=1;
	for (i=k-1;i>=1;i--) {
		rotate(r,qt,n,i,u[i],-u[i+1]);
		if (u[i] == 0.0) u[i]=fabs(u[i+1]);
		else if (fabs(u[i]) > fabs(u[i+1]))
			u[i]=fabs(u[i])*sqrt(1.0+SQR(u[i+1]/u[i]));
		else u[i]=fabs(u[i+1])*sqrt(1.0+SQR(u[i]/u[i+1]));
	}
	for (j=1;j<=n;j++) r[1][j] += u[1]*v[j];
	for (i=1;i<k;i++)
		rotate(r,qt,n,i,r[i][i],-r[i+1][i]);
}
