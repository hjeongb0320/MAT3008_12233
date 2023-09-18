
#include <math.h>
#include "nrutil.h"

void gaucof(n,a,b,amu0,x,w)
float a[],amu0,b[],w[],x[];
int n;
{
	void eigsrt(),tqli();
	int i,j;
	float **z;

	z=matrix(1,n,1,n);
	for (i=1;i<=n;i++) {
		if (i != 1) b[i]=sqrt(b[i]);
		for (j=1;j<=n;j++) z[i][j]=(float)(i == j);
	}
	tqli(a,b,n,z);
	eigsrt(a,z,n);
	for (i=1;i<=n;i++) {
		x[i]=a[i];
		w[i]=amu0*z[1][i]*z[1][i];
	}
	free_matrix(z,1,n,1,n);
}
