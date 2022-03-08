/* Jordan Drakos
 * CSCI 473 - Stencil 2D Serial
 * print-2d.c - The purpose of this piece of the program is to print the data
 *              created from make-2d to the screen in a readable format.
 * 28/01/2022 (created)
 * 06/02/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main (int argc, char *argv[]) {
  int numRows = 0, numCols = 0;
  double **x;

  if (argc != 2) {
    printf("Usage: %s <input data file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *inFile = argv[1];
  printf("Reading in file: %s\n", argv[1]);
  x = readFile(inFile, &numRows, &numCols);
  print2D(x, numRows, numCols);
  free(x);
  exit(0);
}//main
