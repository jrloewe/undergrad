/* Jordan Drakos
 * CSCI 473 - OMP Stencil 2D
 * stencil-2d-stack.c - Performs the nine-point stencil on a matrix read from file
 * and outputs all iterations to an output file.
 * 14/02/2022 (created)
 * 27/02/2022 (last edited)
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/time.h>
 #include "utilities.h"

 int main (int argc, char *argv[]) {
   struct timeval start, end;
   double timeElapsed;

   if (argc != 4) {
     printf("Usage: %s <number of iterations> <input file> <raw stack>\n", argv[0]);
     exit(EXIT_FAILURE);
   }

   int numIterations;
   if ((numIterations = atoi(argv[1])) < 1) {
     printf("At least one iteration is required.\n");
     exit(EXIT_FAILURE);
   }

   char *initData = argv[2], *allData = argv[3];
   if (strcmp(initData, allData) == 0) {
      printf("Data files must all be different files.\n");
      exit(EXIT_FAILURE);
    }

    int rows, cols;
    double **x = readFile(initData, &rows, &cols);
    double **newx = malloc2D(rows, cols);
    populate2D(newx, rows, cols);
    writeData(x, rows, cols, allData);

    gettimeofday(&start, NULL);

    for (int i = 0; i < numIterations; ++i) {
      ninePtStencil(x, newx, rows, cols);
      appendData(newx, rows, cols, allData);
      double **tmp = x;
      x = newx;
      newx = tmp;
    }

    gettimeofday(&end, NULL);
    timeElapsed = timeDiff(&start, &end);
    printf("Time elapsed: %f seconds\n"
           "Rows: %d, Cols: %d, Iterations: %d\n", timeElapsed, rows, cols, numIterations);

    free(x);
    free(newx);
    exit(0);
 }//main
