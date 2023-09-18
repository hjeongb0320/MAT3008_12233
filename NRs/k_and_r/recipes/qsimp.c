
#include <math.h>
#define EPS 1.0e-6
#define JMAX 20

float qsimp(func,a,b)
float (*func)(),a,b;
{
	float trapzd();
	void nrerror();
	int j;
	float s,st,ost=0.0,os=0.0;

	for (j=1;j<=JMAX;j++) {
		st=trapzd(func,a,b,j);
		s=(4.0*st-ost)/3.0;
		if (j > 5)
			if (fabs(s-os) < EPS*fabs(os) ||
				(s == 0.0 && os == 0.0)) return s;
		os=s;
		ost=st;
	}
	nrerror("Too many steps in routine qsimp");
	return 0.0;
}
#undef EPS
#undef JMAX
