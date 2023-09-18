
#include <math.h>

int metrop(de,t)
float de,t;
{
	float ran3();
	static long gljdum=1;

	return de < 0.0 || ran3(&gljdum) < exp(-de/t);
}
