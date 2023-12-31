
#include "nrutil.h"

void trnspt(iorder,ncity,n)
int iorder[],n[],ncity;
{
	int m1,m2,m3,nn,j,jj,*jorder;

	jorder=ivector(1,ncity);
	m1=1 + ((n[2]-n[1]+ncity) % ncity);
	m2=1 + ((n[5]-n[4]+ncity) % ncity);
	m3=1 + ((n[3]-n[6]+ncity) % ncity);
	nn=1;
	for (j=1;j<=m1;j++) {
		jj=1 + ((j+n[1]-2) % ncity);
		jorder[nn++]=iorder[jj];
	}
	for (j=1;j<=m2;j++) {
		jj=1+((j+n[4]-2) % ncity);
		jorder[nn++]=iorder[jj];
	}
	for (j=1;j<=m3;j++) {
		jj=1 + ((j+n[6]-2) % ncity);
		jorder[nn++]=iorder[jj];
	}
	for (j=1;j<=ncity;j++)
		iorder[j]=jorder[j];
	free_ivector(jorder,1,ncity);
}
