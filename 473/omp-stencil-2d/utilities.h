/* Jordan Drakos
 * CSCI 473 - OMP Stencil 2D
 * utilities.h - The associated header file that allows usage of utility functions
 * written in utilities.c.
 * 14/02/2022 (created)
 * 27/02/2022 (last edited)
 */
#ifndef STENCIL_2D_PARALLEL_UTILITIES
#define STENCIL_2D_PARALLEL_UTILITIES

double **malloc2D(int rows, int cols);

void dealloc2D(double** x, int rows);

void populate2D(double **x, int rows, int cols);

void print2D(double **x, int rows, int cols);

void writeFile(double** x, int rows, int cols, char* outFile);

double **readFile(char *inFile, int *rowPt, int *colPt);

void writeData(double **x, int rows, int cols, char *dataFile);

void appendData(double **x, int rows, int cols, char *dataFile);

void ninePtStencil(double **x, double **newx, int rows, int cols);

double timeDiff(struct timeval *start, struct timeval *end);

#endif
