/* Jordan Drakos
 * CSCI 473 - Stencil 2D Serial
 * stencil-2d.c - The purpose of this piece of the program is to perform the
 *                stencil operations on the data.
 * 28/01/2022 (created)
 * 06/02/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main (int argc, char *argv[]) {
  // If the user does not input the proper arguments, inform them of the proper
  // usage and exit.
  if (argc != 5) {
    printf("Usage: ./stencil-2d <number of iterations> <input file> <output file>"
           " <all-iterations>\n");
    exit(EXIT_FAILURE);
  }

  // If the user attempts to perform no iterations, then inform them that at
  // least one iteration is necessary and exit.
  int numIterations;
  if ((numIterations = atoi(argv[1])) < 1) {
    printf("At least one iteration is required.\n");
    exit(EXIT_FAILURE);
  }

  // If the file names of any of the files match, inform the user that each
  // file must have a different name and exit.
  char *initData = argv[2], *finalData = argv[3], *allData = argv[4];
  if ((strcmp(initData, finalData) == 0) || (strcmp(initData, allData) == 0) ||
      (strcmp(finalData, allData) == 0)) {
        printf("Data files must all be different files.\n");
        exit(EXIT_FAILURE);
      }

  int rows, cols;
  double **x = readFile(initData, &rows, &cols);
  double **newx = malloc2D(rows, cols);
  populate2D(newx, rows, cols);
  writeData(x, rows, cols, allData);

  // Perform the 9-point stencil operation based on the number of iterations
  // and append the data to the file used for all iterations.
  for (int i = 0; i < numIterations; ++i) {
    ninePtStencil(x, newx, rows, cols);
    appendData(newx, rows, cols, allData);
    double **tmp = x;
    x = newx;
    newx = tmp;
  }

  // Write the data of the final iteration to the user-specified file and
  // deallocate both matrices before exiting successfully.
  writeFile(x, rows, cols, finalData);
  free(x);
  free(newx);
  exit(0);
}//main
