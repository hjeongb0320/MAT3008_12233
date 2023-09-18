
double ratval(x,cof,mm,kk)
double cof[],x;
int kk,mm;
{
	int j;
	double sumd,sumn;

	for (sumn=cof[mm],j=mm-1;j>=0;j--) sumn=sumn*x+cof[j];
	for (sumd=0.0,j=mm+kk;j>=mm+1;j--) sumd=(sumd+cof[j])*x;
	return sumn/(1.0+sumd);
}
