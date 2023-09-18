
void chsone(bins,ebins,nbins,knstrn,df,chsq,prob)
float *chsq,*df,*prob,bins[],ebins[];
int knstrn,nbins;
{
	float gammq();
	void nrerror();
	int j;
	float temp;

	*df=nbins-knstrn;
	*chsq=0.0;
	for (j=1;j<=nbins;j++) {
		if (ebins[j] <= 0.0) nrerror("Bad expected number in chsone");
		temp=bins[j]-ebins[j];
		*chsq += temp*temp/ebins[j];
	}
	*prob=gammq(0.5*(*df),0.5*(*chsq));
}
