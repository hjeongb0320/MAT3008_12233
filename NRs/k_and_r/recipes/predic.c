
#include "nrutil.h"

void predic(data,ndata,d,m,future,nfut)
float d[],data[],future[];
int m,ndata,nfut;
{
	int k,j;
	float sum,discrp,*reg;

	reg=vector(1,m);
	for (j=1;j<=m;j++) reg[j]=data[ndata+1-j];
	for (j=1;j<=nfut;j++) {
		discrp=0.0;
		sum=discrp;
		for (k=1;k<=m;k++) sum += d[k]*reg[k];
		for (k=m;k>=2;k--) reg[k]=reg[k-1];
		future[j]=reg[1]=sum;
	}
	free_vector(reg,1,m);
}
