#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "nr.h"
#include "nrutil.h"

// 메모리 할당 및 초기화 함수
float** allocateMatrix(int rows, int cols) {
    float** matrix = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float*)malloc(cols * sizeof(float));
    }
    return matrix;
}

float* allocateFloatVector(int size) {
    return (float*)malloc(size * sizeof(float));
}

int* allocateIntVector(int size) {
    return (int*)malloc(size * sizeof(int));
}

void transposeMatrix(float **U, float **UT, int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            UT[j][i] = U[i][j];
        }
    }
}

// Matrix multiplication function
void matrixMultiply(float **A, float **B, float **C, int m, int n, int p) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    FILE *file;
    float** A;
    float** b;
    float** copyA;
    float** copyb;
    float* x;

    char filename[100];
    printf("filename? : ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("파일을 열 수 없습니다.");
        return 1;
    }

    // n*n을 읽어옴
    int n;
    fscanf(file, "%d", &n);
    fscanf(file, "%d", &n);

    // 메모리 할당
    A = allocateMatrix(10, 10);
    b = allocateMatrix(10, 10);
    copyA = allocateMatrix(10, 10);
    copyb = allocateMatrix(10, 10);
    x = allocateFloatVector(10);


    // 파일로부터 행렬 A 읽어오기
    for (int i = 1; i <= n; i++) {  // 행 인덱스
        for (int j = 1; j <= n; j++) {  // 열 인덱스
            fscanf(file, "%f", &A[i][j]); 
        }
    }

    // 벡터 b 읽어오기
    for (int i = 1; i <= n; i++) {
        fscanf(file, "%f", &b[i][1]);
    }

    // 복사본 만들기
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            copyA[i][j] = A[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        copyb[i][1] = b[i][1];
    }    

    fclose(file);

    float mprove_x[10];
    float** alud = allocateMatrix(10,10);
    int mprove_indx[10];
    float mprove_b[10];

    for(int i = 1; i <= n; i++) {
      mprove_b[i] = b[i][1];
    }

    printf("\n1. Gauss Jordan Elimination\n\n");
    gaussj(copyA,n,copyb,n);

    // 해 출력
    for(int i = 1; i <= n; i++) {
      printf("%f ", copyb[i][1]);
    }
    printf("\n");   

    // 복사본 만들기
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
            copyA[i][j] = A[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        copyb[i][1] = b[i][1];
    }

    printf("\n2. LU Decompostion\n\n"); 

    float det = 0.f;
    int* indx = allocateIntVector(10);
    float tempb[10];

    for (int i = 1; i <= n; i++) {
        tempb[i] = b[i][1];
    } 

    ludcmp(copyA,n,indx,&det);
    lubksb(copyA,n,indx,tempb);

    // 해 출력
    for(int i = 1; i <= n; i++) {
      printf("%.20f ", tempb[i]);
      mprove_x[i] = tempb[i];
    }
    printf("\n");

    printf("\nafter mprove..\n"); 

    mprove(A,copyA,n,indx,mprove_b,mprove_x);

    for(int i = 1; i <= n; i++) {
      printf("%.20f ", mprove_x[i]);
    }
    printf("\n");    

    // 복사본 만들기
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            copyA[i][j] = A[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        copyb[i][1] = b[i][1];
    }

    printf("\n3. Singular Value Decompostion\n\n"); 

    float w[10];
    float** v = allocateMatrix(10,10);

    svdcmp(copyA,n,n,w,v);

    float** ut = allocateMatrix(10,10);
    transposeMatrix(copyA,ut,n,n);

    float** temp = allocateMatrix(10,10);
    float** coef = allocateMatrix(10,10);

    for(int i = 1; i <= n; i++) {
      if(w[i] < 1e-6) w[i] = 0.0;
      else w[i] = 1 / w[i];
    }   

    float** ww = allocateMatrix(10,10);
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i == j) ww[i][j] = w[i];
        else ww[i][j] = 0;
      }
    }  

    matrixMultiply(v,ww,temp,n,n,n);

    matrixMultiply(temp,ut,coef,n,n,n);     

    float** answer = allocateMatrix(10,10);

    matrixMultiply(coef,b,answer,n,n,1);

    for(int i = 1; i <= n; i++) {
      printf("%f ", answer[i][1]);
    }
    printf("\n");

    // 복사본 만들기
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            copyA[i][j] = A[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        copyb[i][1] = b[i][1];
    }    

    printf("\n4. Inverse Matrix and Determinant\n\n");     

    float* col = allocateFloatVector(10);
    float** inverse = allocateMatrix(10,10);
    int* new_indx = allocateIntVector(10);

    ludcmp(A,n,new_indx,&det);
    for(int j = 1; j <= n; j++) det *= A[j][j];
    printf("determinant : %f\n\n", det);

    printf("inverse matrix : \n\n");
    for(int j = 1; j <= n; j++) {
      for(int i = 1; i <= n; i++) col[i] = 0.0;
      col[j] = 1.0;
      lubksb(A,n,indx,col);
      for(int i = 1; i <= n; i++) inverse[i][j] = col[i];
    }

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        printf("%f ", inverse[i][j]);
      }
      printf("\n");
    }
}