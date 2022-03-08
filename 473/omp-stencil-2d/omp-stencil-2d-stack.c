/* Jordan Drakos
 * CSCI 473 - OMP Stencil 2D
 * omp-stencil-2d-stack.c - Performs the nine-point stencil on a matrix read from file
 * and outputs all iterations to an output file. Iterations are performed using OpenMP
 * parallelization to provide faster execution.
 * 14/02/2022 (created)
 * 27/02/2022 (last edited)
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <omp.h>
 #include "utilities.h"

 int main (int argc, char *argv[]) {
   if (argc != 5) {
     printf("Usage: %s <num iterations> <input file> <raw stack> <num threads>\n", argv[0]);
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

    int numThreads;
    if ((numThreads = atoi(argv[4])) < 1) {
      printf("Program requires at least one thread.\n");
      exit(EXIT_FAILURE);
    }

    int rows, cols;

    double **x = readFile(initData, &rows, &cols);
    double **newx = malloc2D(rows, cols);
    populate2D(newx, rows, cols);
    writeData(x, rows, cols, allData);

    // Current elapsed wall clock time.
    double start = omp_get_wtime();

    for (int i = 0; i < numIterations; ++i) {
      #pragma omp parallel for num_threads(numThreads)
        for (int i = 1; i < (rows - 1); ++i) {
          for (int j = 1; j < (cols - 1); ++j) {
            newx[i][j] = (x[i-1][j-1] + x[i-1][j]   + x[i-1][j+1] +
                          x[i][j+1]   + x[i+1][j+1] + x[i+1][j] +
                          x[i+1][j-1] + x[i][j-1]   + x[i][j]) / 9.0;
          }
        }
      
      appendData(newx, rows, cols, allData);
      double **tmp = x;
      x = newx;
      newx = tmp;
    }

    // Get the difference of the current elapsed wall clock time and the elapsed
    // wtime from before the stencil operation.
    double timeElapsed = omp_get_wtime() - start;

    // Print the time elapsed as well as the number of rows/cols/iterations/threads.
    printf("Time elapsed: %f seconds\n"
           "Rows: %d, Cols: %d, Iterations: %d, Threads: %d\n", timeElapsed, rows, cols, numIterations, numThreads);

    free(x);
    free(newx);
    exit(0);
 }//main
