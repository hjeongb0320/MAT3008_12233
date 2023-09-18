
void splie2(x1a,x2a,ya,m,n,y2a)
float **y2a,**ya,x1a[],x2a[];
int m,n;
{
	void spline();
	int j;

	for (j=1;j<=m;j++)
		spline(x2a,ya[j],n,1.0e30,1.0e30,y2a[j]);
}
