
#include <math.h>

float beta(z,w)
float w,z;
{
	float gammln();

	return exp(gammln(z)+gammln(w)-gammln(z+w));
}
