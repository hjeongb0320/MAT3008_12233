#include <stdio.h>
#include "nr.h"

void get_float_eps(float *eps){
  *eps = 0.f;
	//Your Implementation

  float token = 2.f;
  while(1) {
    if(1 + token == 1) break;
    token /= 2;
  }

  *eps = token * 2;
}

void get_double_eps(double *double_eps){
  *double_eps = 0.0;
	//Your Implementation

  double token = 2.0;
  while(1) {
    if(1 + token == 1) break;
    token /= 2;
  }

  *double_eps = token * 2;
}

int main(){
	int ibeta, it, irnd, ngrd, machep, negep, iexp, minexp, maxexp;
	float eps, epsneg, xmin, xmax;
  double double_eps, double_epsneg, double_xmin, double_xmax;

  printf("Homework #1\n\n");
  printf("Method 1: Use the routine machar() in NR in C\n");

	machar_float(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
			&eps, &epsneg, &xmin, &xmax);
	printf("Machine Accuracy (machar_float): \t%0.20f\n", eps);

	machar_double(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
			&double_eps, &double_epsneg, &double_xmin, &double_xmax);
	printf("Machine Accuracy (machar_double): \t%0.20f\n", double_eps);

  printf("\nMethod 2: Use your own code, get_eps()\n");

	get_float_eps(&eps);
	printf("Machine Accuracy (get_float_eps): \t%0.20f\n", eps);

  get_double_eps(&double_eps);
	printf("Machine Accuracy (get_double_eps): \t%0.20f\n", double_eps);

	return 0;
}
