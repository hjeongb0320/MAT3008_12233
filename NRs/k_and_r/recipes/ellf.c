
#include <math.h>
#include "nrutil.h"

float ellf(phi,ak)
float ak,phi;
{
	float rf();
	float s;

	s=sin(phi);
	return s*rf(SQR(cos(phi)),(1.0-s*ak)*(1.0+s*ak),1.0);
}
