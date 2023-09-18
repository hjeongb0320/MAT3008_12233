
#include <math.h>

void sprsin(a,n,thresh,nmax,sa,ija)
float **a,sa[],thresh;
int n;
unsigned long ija[],nmax;
{
	void nrerror();
	int i,j;
	unsigned long k;

	for (j=1;j<=n;j++) sa[j]=a[j][j];
	ija[1]=n+2;
	k=n+1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (fabs(a[i][j]) >= thresh && i != j) {
				if (++k > nmax) nrerror("sprsin: nmax too small");
				sa[k]=a[i][j];
				ija[k]=j;
			}
		}
		ija[i+1]=k+1;
	}
}
