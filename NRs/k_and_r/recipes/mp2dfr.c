
#define IAZ 48

void mp2dfr(a,s,n,m)
int *m,n;
unsigned char a[],s[];
{
	void mplsh(),mpsmu();
	int j;

	*m=(int) (2.408*n);
	for (j=1;j<=(*m);j++) {
		mpsmu(a,a,n,10);
		s[j]=a[1]+IAZ;
		mplsh(a,n);
	}
}
#undef IAZ
