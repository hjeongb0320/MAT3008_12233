
extern long idum;

void ranpt(pt,regn,n)
float pt[],regn[];
int n;
{
	float ran1();
	int j;

	for (j=1;j<=n;j++)
		pt[j]=regn[j]+(regn[n+j]-regn[j])*ran1(&idum);
}
