
#include <math.h>

double snrm(n,sx,itol)
double sx[];
int itol;
unsigned long n;
{
	unsigned long i,isamax;
	double ans;

	if (itol <= 3) {
		ans = 0.0;
		for (i=1;i<=n;i++) ans += sx[i]*sx[i];
		return sqrt(ans);
	} else {
		isamax=1;
		for (i=1;i<=n;i++) {
			if (fabs(sx[i]) > fabs(sx[isamax])) isamax=i;
		}
		return fabs(sx[isamax]);
	}
}
