
extern unsigned long ija[];
extern double sa[];

void asolve(n,b,x,itrnsp)
double b[],x[];
int itrnsp;
unsigned long n;
{
	unsigned long i;

	for(i=1;i<=n;i++) x[i]=(sa[i] != 0.0 ? b[i]/sa[i] : b[i]);
}
