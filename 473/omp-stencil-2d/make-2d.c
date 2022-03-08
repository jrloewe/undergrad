/* Jordan Drakos
 * CSCI 473 - OMP Stencil 2D
 * make-2d.c - The purpose of this piece of the program is to create the initial
 * conditions and boundary values.
 * 14/02/2022 (created)
 * 27/02/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *argv[]) {
  int numRows, numCols;
  char *outFile;

  if (argc != 4) {
    printf("Usage: %s <# rows> <# columns> <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((numRows = atoi(argv[1])) < 4 || (numCols = atoi(argv[2])) < 4) {
    printf("At least four rows and four columns are required for operation.\n");
    exit(EXIT_FAILURE);
  }

  double **x = malloc2D(numRows, numCols);
  outFile = argv[3];
  populate2D(x, numRows, numCols);
  writeFile(x, numRows, numCols, outFile);
  free(x);
  exit(0);
}//main
