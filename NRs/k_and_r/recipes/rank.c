
void rank(n,indx,irank)
unsigned long indx[],irank[],n;
{
	unsigned long j;

	for (j=1;j<=n;j++) irank[indx[j]]=j;
}
