
#include <math.h>

float bico(n,k)
int k,n;
{
	float factln();

	return floor(0.5+exp(factln(n)-factln(k)-factln(n-k)));
}
