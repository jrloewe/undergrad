/* Jordan Drakos
 * CSCI 473 - OMP Stencil 2D
 * utilities.c - Provides utility functions to be used throughout the various
 * pieces of the application.
 * 14/02/2022 (created)
 * 27/02/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

// Allocates space for a 2D matrix of user-specified size.
double **malloc2D(int rows, int cols)
{
   double **x = (double **)malloc(rows*sizeof(double *) + rows*cols*sizeof(double));
   x[0] = (double *)(x + rows);

   for (int j = 1; j < rows; j++) {
      x[j] = x[j-1] + cols;
   }

   return(x);
}

// Populates the base values of the matrix (i.e. 1.0 in the first and last columns
// and 0.0 in the others).
void populate2D(double **x, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    double *curr = x[i];
    curr[0] = curr[cols - 1] = 1.0;
  }

  for (int i = 0; i < rows; ++i) {
    double *curr = x[i];
    curr[0] = curr[cols - 1] = 1.0;
    for (int j = 1; j < (cols - 1); ++j) {
      curr[j] = 0.0;
    }
  }
}//populateMatrix

// Prints a matrix to the screen in a formatted output.
void print2D(double **x, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      // Based on the specifications, it seems that we want to use tab
      // spacing when printing.
      printf("%.2f\t", x[i][j]);
    }

    printf("\n");
  }
}//printMatrix

// Writes the generated data to a user-specified file.
void writeFile(double **x, int rows, int cols, char *outFile) {
  FILE *fp = fopen(outFile, "w");
  fwrite(&rows, 1, sizeof(int), fp);
  fwrite(&cols, 1, sizeof(int), fp);

  for (int i = 0; i < rows; ++i) {
    fwrite(x[i], 1, (cols * sizeof(double)), fp);
  }

  fclose(fp);
}//writeFile

// Reads data from a user-specified file.
double **readFile(char *inFile, int *rowPt, int *colPt) {
  FILE *fp = fopen(inFile, "r");

  fread(rowPt, 1, sizeof(int), fp);
  fread(colPt, 1, sizeof(int), fp);

  // Because it's being read from a file, we need to allocate space and create
  // a matrix to hold the data.
  double **x = malloc2D(*rowPt, *colPt);
  for (int i = 0; i < *rowPt; ++i) {
    fread(x[i], 1, (*colPt * sizeof(double)), fp);
  }

  fclose(fp);
  return x;
}//readFile

// Used to write data to a user-specified file.
void writeData(double **x, int rows, int cols, char *dataFile) {
  FILE *fp = fopen(dataFile, "w");
  for (int i = 0; i < rows; ++i) {
    fwrite(x[i], 1, (cols * sizeof(double)), fp);
  }

  fclose(fp);
}//writeData

// Used to append data to a user-specified file; it is necessary to use this
// in conjunction with the writeData function so as to not overwrite existing data.
void appendData(double **x, int rows, int cols, char *dataFile) {
  FILE *fp = fopen(dataFile, "a");
  for (int i = 0; i < rows; ++i) {
    fwrite(x[i], 1, (cols * sizeof(double)), fp);
  }

  fclose(fp);
}//appendData

// Performs the 9-point stencil operation with the order of operations
// (NW + N + NE + E + SE + S + SW + W + C) / 9.0.
void ninePtStencil(double **x, double **newx, int rows, int cols) {
  for (int i = 1; i < (rows - 1); ++i) {
    for (int j = 1; j < (cols - 1); ++j) {
      newx[i][j] = (x[i-1][j-1] + x[i-1][j]   + x[i-1][j+1] +
                    x[i][j+1]   + x[i+1][j+1] + x[i+1][j] +
                    x[i+1][j-1] + x[i][j-1]   + x[i][j]) / 9.0;
    }
  }
}//ninePtStencil

double timeDiff(struct timeval *start, struct timeval *end) {
  return (double) (end->tv_usec - start->tv_usec) / 1000000 + (double) (end->tv_sec - start->tv_sec);
}//timeDiff
