/* Jordan Drakos
 * CSCI 473 - OMP Stencil 2D
 * stencil-2d.c - The purpose of this piece of the program is to perform the
 * stencil operations on the data. Compared to the previous version of the program,
 * this version only outputs the final iteration to a user-specified file.
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
    printf("Usage: %s <number of iterations> <input file> <output file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int numIterations;
  if ((numIterations = atoi(argv[1])) < 1) {
    printf("At least one iteration is required.\n");
    exit(EXIT_FAILURE);
  }

  char *initData = argv[2], *finalData = argv[3];
  if (strcmp(initData, finalData) == 0) {
        printf("Data files must be different files.\n");
        exit(EXIT_FAILURE);
      }

  int rows, cols;
  double **x = readFile(initData, &rows, &cols);
  double **newx = malloc2D(rows, cols);
  populate2D(newx, rows, cols);

  gettimeofday(&start, NULL);

  for (int i = 0; i < numIterations; ++i) {
    ninePtStencil(x, newx, rows, cols);
    double **tmp = x;
    x = newx;
    newx = tmp;
  }

  gettimeofday(&end, NULL);
  timeElapsed = timeDiff(&start, &end);
  writeFile(x, rows, cols, finalData);

  // Print elapsed time, number of rows/columns/iterations.
  printf("Time elapsed: %f seconds\n"
         "Rows: %d, Cols: %d, Iterations: %d\n", timeElapsed, rows, cols, numIterations);

  free(x);
  free(newx);
  exit(0);
}//main
