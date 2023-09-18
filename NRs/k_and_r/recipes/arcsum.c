
void arcsum(iin,iout,ja,nwk,nrad,nc)
int nwk;
unsigned long iin[],iout[],ja,nc,nrad;
{
	int j,karry=0;
	unsigned long jtmp;

	for (j=nwk;j>nc;j--) {
		jtmp=ja;
		ja /= nrad;
		iout[j]=iin[j]+(jtmp-ja*nrad)+karry;
		if (iout[j] >= nrad) {
			iout[j] -= nrad;
			karry=1;
		} else karry=0;
	}
	iout[nc]=iin[nc]+ja+karry;
}
