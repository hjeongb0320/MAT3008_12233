#include <math.h>
#define MAXIT 30

float muller(float (*func)(float), float x0, float x1, float xacc)
{
	void nrerror(char error_text[]);

  float p0, p1, p2, p3, a, b, c;
  int j = 0;

  p0 = x0;
  p1 = x1;
  p2 = (x0 + x1) / 2;

  do {
    c = func(p2);
    b = (pow(p0 - p2, 2) * (func(p1) - func(p2)) - pow(p1 - p2, 2) * (func(p0) - func(p2))) / ((p0 - p2) * (p1 - p2) * (p0 - p1));
    a = ((p1 - p2) * (func(p0) - func(p2)) - (p0 - p2) * (func(p1) - func(p2))) / ((p0 - p2) * (p1 - p2) * (p0 - p1));
    
    float sign = 1;
    if(b < 0) sign = -1;

    p3 = p2 - ((2 * c) / (b + sign * sqrtf(pow(b,2) - (4 * a * c))));
    j++;

    if(fabs(p3 - p2) <= xacc) return p3;

    p0 = p1;
    p1 = p2;
    p2 = p3;
  } while (j != MAXIT);

	nrerror("Maximum number of iterations exceeded in muller");
	return 0.0;
}
#undef MAXIT
