
void dsprstx(sa,ija,x,b,n)
double b[],sa[],x[];
unsigned long ija[],n;
{
	void nrerror();
	unsigned long i,j,k;
	if (ija[1] != n+2) nrerror("mismatched vector and matrix in dsprstx");
	for (i=1;i<=n;i++) b[i]=sa[i]*x[i];
	for (i=1;i<=n;i++) {
		for (k=ija[i];k<=ija[i+1]-1;k++) {
			j=ija[k];
			b[j] += sa[k]*x[i];
		}
	}
}
