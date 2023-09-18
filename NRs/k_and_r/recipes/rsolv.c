
void rsolv(a,n,d,b)
float **a,b[],d[];
int n;
{
	int i,j;
	float sum;

	b[n] /= d[n];
	for (i=n-1;i>=1;i--) {
		for (sum=0.0,j=i+1;j<=n;j++) sum += a[i][j]*b[j];
		b[i]=(b[i]-sum)/d[i];
	}
}
