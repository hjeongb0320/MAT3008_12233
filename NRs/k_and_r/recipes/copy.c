
void copy(aout,ain,n)
double **ain,**aout;
int n;
{
	int i,j;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			aout[j][i]=ain[j][i];

}
