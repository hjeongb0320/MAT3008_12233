
void hufapp(index,nprob,n,i)
unsigned long i,index[],n,nprob[];
{
	unsigned long j,k;

	k=index[i];
	while (i <= (n>>1)) {
		if ((j = i << 1) < n && nprob[index[j]] > nprob[index[j+1]]) j++;
		if (nprob[k] <= nprob[index[j]]) break;
		index[i]=index[j];
		i=j;
	}
	index[i]=k;
}
