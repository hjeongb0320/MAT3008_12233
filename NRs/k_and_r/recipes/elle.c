
#include <math.h>
#include "nrutil.h"

float elle(phi,ak)
float ak,phi;
{
	float rd(),rf();
	float cc,q,s;

	s=sin(phi);
	cc=SQR(cos(phi));
	q=(1.0-s*ak)*(1.0+s*ak);
	return s*(rf(cc,q,1.0)-(SQR(s*ak))*rd(cc,q,1.0)/3.0);
}
