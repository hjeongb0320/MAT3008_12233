#include <stdio.h>
#include <time.h>
#include "nr.h"
#include "nrutil.h"

void generate_ran1(int num) {
    long seed = time(NULL);
    float random_sample;
    // Open a file for writing
    FILE *file = fopen("ran1.txt", "w");
    
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < num; i++) {
        float temp = ran1(&seed);
        random_sample = (ran1(&seed) * 7) - 3;  // Generate a random sample using ran1 function
        fprintf(file, "%f\n", random_sample);  // Write the random sample to the file
    }
    
    // Close the file
    fclose(file);

    printf("%d random samples written to 'ran1.txt'.\n", num);
}

void generate_gauss(int num) {
    long seed = time(NULL);
    float random_sample;
    // Open a file for writing
    FILE *file = fopen("gauss.txt", "w");
    
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < num; i++) {
        float temp = gasdev(&seed);
        random_sample = gasdev(&seed) * 1.5 + 0.5;  // Generate a random sample using ran1 function
        fprintf(file, "%f\n", random_sample);  // Write the random sample to the file
    }
    
    // Close the file
    fclose(file);

    printf("%d random samples written to 'gauss.txt'.\n", num);
}

int main() {
  int num;
  printf("Generating number?\n");
  scanf("%d", &num);

  generate_ran1(num);
  generate_gauss(num);
}