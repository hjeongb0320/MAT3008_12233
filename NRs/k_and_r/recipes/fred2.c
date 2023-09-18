
#include "nrutil.h"

void fred2(n,a,b,t,f,w,g,ak)
float (*ak)(),(*g)(),a,b,f[],t[],w[];
int n;
{
	void gauleg(),lubksb(),ludcmp();
	int i,j,*indx;
	float d,**omk;

	indx=ivector(1,n);
	omk=matrix(1,n,1,n);
	gauleg(a,b,t,w,n);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++)
			omk[i][j]=(float)(i == j)-(*ak)(t[i],t[j])*w[j];
		f[i]=(*g)(t[i]);
	}
	ludcmp(omk,n,indx,&d);
	lubksb(omk,n,indx,f);
	free_matrix(omk,1,n,1,n);
	free_ivector(indx,1,n);
}
