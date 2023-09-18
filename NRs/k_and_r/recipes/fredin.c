
float fredin(x,n,a,b,t,f,w,g,ak)
float (*ak)(),(*g)(),a,b,f[],t[],w[],x;
int n;
{
	int i;
	float sum=0.0;

	for (i=1;i<=n;i++) sum += (*ak)(x,t[i])*w[i]*f[i];
	return (*g)(x)+sum;
}
