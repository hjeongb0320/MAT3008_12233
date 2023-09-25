#include<math.h>

float nonlinear_equation(float x) {
    return exp(x) - pow(x, 3) + 5;
}

float derivative(float x) {
    return exp(x) - 3 * x * x;
}