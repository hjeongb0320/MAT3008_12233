
void chstwo(bins1,bins2,nbins,knstrn,df,chsq,prob)
float *chsq,*df,*prob,bins1[],bins2[];
int knstrn,nbins;
{
	float gammq();
	int j;
	float temp;

	*df=nbins-knstrn;
	*chsq=0.0;
	for (j=1;j<=nbins;j++)
		if (bins1[j] == 0.0 && bins2[j] == 0.0)
			--(*df);
		else {
			temp=bins1[j]-bins2[j];
			*chsq += temp*temp/(bins1[j]+bins2[j]);
		}
	*prob=gammq(0.5*(*df),0.5*(*chsq));
}
