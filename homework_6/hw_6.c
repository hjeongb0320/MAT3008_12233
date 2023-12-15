#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nr.h"
#include "nrutil.h"

typedef double** Matrix;
typedef double** Vector;

void allocateMatrix(Matrix* mat, int rows, int cols) {
    *mat = malloc(sizeof(double*) * rows);
    for (int i = 0; i < rows; i++) {
        (*mat)[i] = malloc(sizeof(double) * cols);
    }
}

void deallocateMatrix(Matrix* mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free((*mat)[i]);
    }
    free(*mat);
}

void readData(FILE* fp, double** mat_x, double** mat_y, double** vec_x, double** vec_y) {
    double x, y, xp, yp;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0, sumXP = 0, sumYP = 0, sumXXP = 0, sumYXP = 0, sumXYP = 0, sumYYP = 0, sumN = 0;

    while (fscanf(fp, "%lf %lf %lf %lf", &x, &y, &xp, &yp) == 4) {
        sumX += x;
        sumY += y;
        sumXY += x * y;
        sumX2 += x * x;
        sumY2 += y * y;
        sumXP += xp;
        sumYP += yp;
        sumXXP += x * xp;
        sumYXP += y * xp;
        sumXYP += x * yp;
        sumYYP += y * yp;
        sumN += 1;
    }

    mat_x[1][1] = sumX2;
    mat_x[1][2] = sumXY;
    mat_x[1][3] = sumX;
    mat_x[2][1] = sumXY;
    mat_x[2][2] = sumY2;
    mat_x[2][3] = sumY;
    mat_x[3][1] = sumX;
    mat_x[3][2] = sumY;
    mat_x[3][3] = sumN;

    mat_y[1][1] = sumX2;
    mat_y[1][2] = sumXY;
    mat_y[1][3] = sumX;
    mat_y[2][1] = sumXY;
    mat_y[2][2] = sumY2;
    mat_y[2][3] = sumY;
    mat_y[3][1] = sumX;
    mat_y[3][2] = sumY;
    mat_y[3][3] = sumN;

    vec_x[1][1] = sumXXP;
    vec_y[1][1] = sumXXP;
    vec_x[2][1] = sumYXP;
    vec_y[2][1] = sumYYP;
    vec_x[3][1] = sumXP;
    vec_y[3][1] = sumYP;
}

int main() {
    char* fileNames[3] = {"fitdata1.dat", "fitdata2.dat", "fitdata3.dat"};

    Matrix matrixX, matrixY;
    Vector vectorX, vectorY;
    FILE* file;

    allocateMatrix(&matrixX, 4, 4);
    allocateMatrix(&matrixY, 4, 4);

    allocateMatrix(&vectorX, 4, 2);
    allocateMatrix(&vectorY, 4, 2);

    for (int fileIndex = 0; fileIndex < 3; fileIndex++) {
        file = fopen(fileNames[fileIndex], "r");
        if (file == NULL) {
            printf("Error: Unable to open file %s\n", fileNames[fileIndex]);
            return 1;
        }
        readData(file, matrixX, matrixY, vectorX, vectorY);

        gaussj(matrixX, 3, vectorX, 1);

        printf("=============== Fit Data %d ===============\n", fileIndex + 1);
        printf("Coefficients for X:\n");
        printf(" a1: %lf\n a2: %lf\n a3: %lf\n", vectorX[1][1], vectorX[2][1], vectorX[3][1]);

        gaussj(matrixY, 3, vectorY, 1);

        printf("Coefficients for Y:\n");
        printf(" a4: %lf\n a5: %lf\n a6: %lf\n", vectorY[1][1], vectorY[2][1], vectorY[3][1]);
        printf("=========================================\n\n");
        fclose(file);
    }

    deallocateMatrix(&matrixX, 4);
    deallocateMatrix(&matrixY, 4);
    deallocateMatrix(&vectorX, 4);
    deallocateMatrix(&vectorY, 4);

    return 0;
}