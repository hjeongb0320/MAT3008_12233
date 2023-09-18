
void matsub(a,b,c,n)
double **a,**b,**c;
int n;
{
	int i,j;

	for (j=1;j<=n;j++)
		for (i=1;i<=n;i++)
			c[i][j]=a[i][j]-b[i][j];
}
