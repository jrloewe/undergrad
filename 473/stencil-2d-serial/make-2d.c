/* Jordan Drakos
 * CSCI 473 - Stencil 2D Serial
 * make-2d.c - The purpose of this piece of the program is to create the initial
 *             conditions and boundary values.
 * 28/01/2022 (created)
 * 06/02/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *argv[]) {
  int numRows, numCols;
  char *outFile;

  // If the user does not input the proper amount of arguments, then print
  // a message informing them of the proper usage and exit.
  if (argc != 4) {
    printf("Usage: %s <# rows> <# columns> <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // To have the program perform the operations in the way we want them to, the
  // matrix needs to be of a certain size, at least 4x4 I believe. So if either
  // dimension is smaller than 4, exit after informing the user of this.
  if ((numRows = atoi(argv[1])) < 4 || (numCols = atoi(argv[2])) < 4) {
    printf("At least four rows and four columns are required for operation.\n");
    exit(EXIT_FAILURE);
  }

  // Once the number of rows/columns and filename have been read in, create the
  // matrix to the user's specifications, populate it with the base values,
  // write it to the specified file, then deallocate the memory and exit.
  double **x = malloc2D(numRows, numCols);
  outFile = argv[3];
  populate2D(x, numRows, numCols);
  writeFile(x, numRows, numCols, outFile);
  free(x);
  exit(0);
}//main
