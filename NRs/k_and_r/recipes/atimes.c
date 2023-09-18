
extern unsigned long ija[];
extern double sa[];

void atimes(n,x,r,itrnsp)
double r[],x[];
int itrnsp;
unsigned long n;
{
	void dsprsax(),dsprstx();

	if (itrnsp) dsprstx(sa,ija,x,r,n);
	else dsprsax(sa,ija,x,r,n);
}
