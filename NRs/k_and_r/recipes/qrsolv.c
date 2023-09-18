
void qrsolv(a,n,c,d,b)
float **a,b[],c[],d[];
int n;
{
	void rsolv();
	int i,j;
	float sum,tau;

	for (j=1;j<n;j++) {
		for (sum=0.0,i=j;i<=n;i++) sum += a[i][j]*b[i];
		tau=sum/c[j];
		for (i=j;i<=n;i++) b[i] -= tau*a[i][j];
	}
	rsolv(a,n,d,b);
}
