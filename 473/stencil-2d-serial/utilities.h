/* Jordan Drakos
 * CSCI 473 - Stencil 2D Serial
 * utilities.h - The associated header file that allows usage of utility functions
 *               written in utilities.c.
 * 28/01/2022 (created)
 * 06/02/2022 (last edited)
 */
#ifndef STENCIL_2D_SERIAL_UTILITIES
#define STENCIL_2D_SERIAL_UTILITIES

double **malloc2D(int rows, int cols);

void populate2D(double **x, int rows, int cols);

void print2D(double **x, int rows, int cols);

void writeFile(double** x, int rows, int cols, char* outFile);

double **readFile(char *inFile, int *rowPt, int *colPt);

void writeData(double **x, int rows, int cols, char *dataFile);

void appendData(double **x, int rows, int cols, char *dataFile);

void ninePtStencil(double **x, double **newx, int rows, int cols);

#endif
