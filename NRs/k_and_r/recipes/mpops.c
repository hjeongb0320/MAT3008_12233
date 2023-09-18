
#define LOBYTE(x) ((unsigned char) ((x) & 0xff))
#define HIBYTE(x) ((unsigned char) ((x) >> 8 & 0xff))


void mpadd(w,u,v,n)
int n;
unsigned char u[],v[],w[];
{
	int j;
	unsigned short ireg=0;

	for (j=n;j>=1;j--) {
		ireg=u[j]+v[j]+HIBYTE(ireg);
		w[j+1]=LOBYTE(ireg);
	}
	w[1]=HIBYTE(ireg);
}

void mpsub(is,w,u,v,n)
int *is,n;
unsigned char u[],v[],w[];
{
	int j;
	unsigned short ireg=256;

	for (j=n;j>=1;j--) {
		ireg=255+u[j]-v[j]+HIBYTE(ireg);
		w[j]=LOBYTE(ireg);
	}
	*is=HIBYTE(ireg)-1;
}

void mpsad(w,u,n,iv)
int iv,n;
unsigned char u[],w[];
{
	int j;
	unsigned short ireg;

	ireg=256*iv;
	for (j=n;j>=1;j--) {
		ireg=u[j]+HIBYTE(ireg);
		w[j+1]=LOBYTE(ireg);
	}
	w[1]=HIBYTE(ireg);
}

void mpsmu(w,u,n,iv)
int iv,n;
unsigned char u[],w[];
{
	int j;
	unsigned short ireg=0;

	for (j=n;j>=1;j--) {
		ireg=u[j]*iv+HIBYTE(ireg);
		w[j+1]=LOBYTE(ireg);
	}
	w[1]=HIBYTE(ireg);
}

void mpsdv(w,u,n,iv,ir)
int *ir,iv,n;
unsigned char u[],w[];
{
	int i,j;

	*ir=0;
	for (j=1;j<=n;j++) {
		i=256*(*ir)+u[j];
		w[j]=(unsigned char) (i/iv);
		*ir=i % iv;
	}
}

void mpneg(u,n)
int n;
unsigned char u[];
{
	int j;
	unsigned short ireg=256;

	for (j=n;j>=1;j--) {
		ireg=255-u[j]+HIBYTE(ireg);
		u[j]=LOBYTE(ireg);
	}
}

void mpmov(u,v,n)
int n;
unsigned char u[],v[];
{
	int j;

	for (j=1;j<=n;j++) u[j]=v[j];
}

void mplsh(u,n)
int n;
unsigned char u[];
{
	int j;

	for (j=1;j<=n;j++) u[j]=u[j+1];
}
#undef LOBYTE
#undef HIBYTE
