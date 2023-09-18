
#include "nrutil.h"

void correl(data1,data2,n,ans)
float ans[],data1[],data2[];
unsigned long n;
{
	void realft(),twofft();
	unsigned long no2,i;
	float dum,*fft;

	fft=vector(1,n<<1);
	twofft(data1,data2,fft,ans,n);
	no2=n>>1;
	for (i=2;i<=n+2;i+=2) {
		ans[i-1]=(fft[i-1]*(dum=ans[i-1])+fft[i]*ans[i])/no2;
		ans[i]=(fft[i]*dum-fft[i-1]*ans[i])/no2;
	}
	ans[2]=ans[n+1];
	realft(ans,n,-1);
	free_vector(fft,1,n<<1);
}
