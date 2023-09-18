
void addint(uf,uc,res,nf)
double **res,**uc,**uf;
int nf;
{
	void interp();
	int i,j;

	interp(res,uc,nf);
	for (j=1;j<=nf;j++)
		for (i=1;i<=nf;i++)
			uf[i][j] += res[i][j];
}
