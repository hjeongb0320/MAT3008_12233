#include <stdio.h>
#include <stdint.h>
#include <mach/mach_time.h>
#include "nr.h"
#include "nrutil.h"

float func(float x, float* a, float* b) {
  *a = bessj0(x);
  *b = -bessj1(x);
}

float myfunc(float x, float* a, float* b) {
  *a = nonlinear_equation(x);
  *b = derivative(x);
}

int main() {

  // 0. find interval
  float (*bessj0FunctionPtr)(float) = bessj0;
  float bessj0_xb1[100];
  float bessj0_xb2[100];
  int bessj0_nb = 0;

  float (*bessj1FunctionPtr)(float) = bessj1;
  float bessj1_xb1[100];
  float bessj1_xb2[100];
  int bessj1_nb = 0;

  float (*myFuncPtr)(float) = nonlinear_equation;
  float myFunc_xb1[100];
  float myFunc_xb2[100];
  int myFunc_nb = 0;

  zbrak(bessj0FunctionPtr, 1.0, 10.0, 100, bessj0_xb1, bessj0_xb2, &bessj0_nb);
  zbrak(bessj1FunctionPtr, 1.0, 10.0, 100, bessj1_xb1, bessj1_xb2, &bessj1_nb);
  zbrak(myFuncPtr, 1.0, 10.0, 100, myFunc_xb1, myFunc_xb2, &myFunc_nb);

  /*
    Zero-crossing interval - bessi0 func 1: [2.404047, 2.404947]
    Zero-crossing interval - bessi0 func 2: [5.519549, 5.520449]
    Zero-crossing interval - bessi0 func 3: [8.652969, 8.653870]

    Zero-crossing interval - bessi1 func 1: [3.831495, 3.832395]
    Zero-crossing interval - bessi1 func 2: [7.015003, 7.015903]
  */

  float xacc = 0.000001;

  uint64_t start_time, end_time;
  double elapsed_time;
  mach_timebase_info_data_t timebase;

  mach_timebase_info(&timebase);

  // 1. Bisection
  printf("\n1. Bisection\n\n");
  printf("<Bessj0>\n");
  for(int i = 1; i <= bessj0_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtbis(bessj0FunctionPtr, bessj0_xb1[i], bessj0_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  printf("\n<Myfunc>\n");
  for(int i = 1; i <= myFunc_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtbis(myFuncPtr, myFunc_xb1[i], myFunc_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  // 2. Linear interpolation
  printf("\n2. Linear interpolation\n\n");
  printf("<Bessj0>\n");
  for(int i = 1; i <= bessj0_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtflsp(bessj0FunctionPtr, bessj0_xb1[i], bessj0_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  printf("\n<Myfunc>\n");
  for(int i = 1; i <= myFunc_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtflsp(myFuncPtr, myFunc_xb1[i], myFunc_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  // 3. Secant
  printf("\n3. Secant\n\n");
  printf("<Bessj0>\n");
  for(int i = 1; i <= bessj0_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtsec(bessj0FunctionPtr, bessj0_xb1[i], bessj0_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  printf("\n<Myfunc>\n");
  for(int i = 1; i <= myFunc_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtsec(myFuncPtr, myFunc_xb1[i], myFunc_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }  

  // 4. Newton-Raphson
  printf("\n4. Newtion-Raphson\n\n");
  printf("<Bessj0>\n");
  for(int i = 1; i <= bessj0_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtnewt(func, bessj0_xb1[i], bessj0_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  printf("\n<Myfunc>\n");
  for(int i = 1; i <= myFunc_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtnewt(myfunc, myFunc_xb1[i], myFunc_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }  

  // 5. Newton with bracketing
  printf("\n5. Newton with bracketing\n\n");
  printf("<Bessj0>\n");
  for(int i = 1; i <= bessj0_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtsafe(func, bessj0_xb1[i], bessj0_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  printf("\n<Myfunc>\n");
  for(int i = 1; i <= myFunc_nb; i++) {
    start_time = mach_absolute_time();
    float now = rtsafe(myfunc, myFunc_xb1[i], myFunc_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }  

  // 6. muller's method
  printf("\n5. muller's method\n\n");
  printf("<Bessj0>\n");
  for(int i = 1; i <= bessj0_nb; i++) {
    start_time = mach_absolute_time();
    float now = muller(bessj0FunctionPtr, bessj0_xb1[i], bessj0_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }

  printf("\n<Myfunc>\n");
  for(int i = 1; i <= myFunc_nb; i++) {
    start_time = mach_absolute_time();
    float now = muller(myFuncPtr, myFunc_xb1[i], myFunc_xb2[i], xacc);
    end_time = mach_absolute_time();
    elapsed_time = (double)(end_time - start_time) * timebase.numer / timebase.denom / 1e9;
    printf("answer %d : %f // execution_time : %.20f\n", i, now, elapsed_time);
  }  
}