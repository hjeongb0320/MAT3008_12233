
void wt1(a,n,isign,wtstep)
float a[];
int isign;
unsigned long n;
void (*wtstep)();
{
	unsigned long nn;

	if (n < 4) return;
	if (isign >= 0) {
		for (nn=n;nn>=4;nn>>=1) (*wtstep)(a,nn,isign);
	} else {
		for (nn=4;nn<=n;nn<<=1) (*wtstep)(a,nn,isign);
	}
}
