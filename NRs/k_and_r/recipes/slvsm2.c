
#include <math.h>

void slvsm2(u,rhs)
double **rhs,**u;
{
	void fill0();
	double disc,fact,h=0.5;

	fill0(u,3);
	fact=2.0/(h*h);
	disc=sqrt(fact*fact+rhs[2][2]);
	u[2][2] = -rhs[2][2]/(fact+disc);
}
