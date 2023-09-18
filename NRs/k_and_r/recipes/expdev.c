
#include <math.h>

float expdev(idum)
long *idum;
{
	float ran1();
	float dum;

	do
		dum=ran1(idum);
	while (dum == 0.0);
	return -log(dum);
}
