/* Jordan Drakos
 * CSCI 473 - Leibniz Pi Serial
 * pi_serial.c - Calculates the value of pi using the Leibniz formula based on
 *               the number of user-specified terms.
 * 11/02/2022 (created)
 * 13/02/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (int argc, char* argv[]) {
  // Declare the variables used in the course of the program; numTerms is
  // unsigned due to the fact that we will only have a positive number of terms
  // and long int for running it for more than 65535 terms.
  double pi, sum;
  unsigned long int numTerms;

  // If the user does not input two arguments, print an error informing them of
  // the proper usage and exit.
  if (argc != 2) {
    printf("Usage: %s <number of terms>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // The first value of the Leibniz is series is ((-1)^k / 2k+1) = 1, which occurs
  // when k = 0, so the minimum number of terms should be 1.
  numTerms = atoi(argv[1]);
  if (numTerms < 1) {
    printf("Number of terms should be a positive non-zero number.\n");
    exit(EXIT_FAILURE);
  }

  // Get the clock time just before performing the loop.
  clock_t start = clock();

  // Calculate the sum of  (-1)^k / 2k+1 for k = 0 to the specified number of terms.
  for (unsigned long int k = 0; k < numTerms; ++k) {
    sum += pow(-1, k) / (2 * k + 1);
  }

  // Multiply the sum by four (4) to get the value of pi based on the number of terms.
  pi = 4 * sum;

  // Get the clock time after performing all calculations and get the elapsed time
  // of these operations by subtracting the end clock time by the start clock time
  // and dividing them by CLOCKS_PER_SEC.
  clock_t end = clock();
  double timeElapsed = (double) (end - start) / CLOCKS_PER_SEC;

  // Print the value of pi and the time elapsed to the screen.
  printf("Value of pi based on %lu terms: %.17f\n", numTerms, pi);
  printf("Time elapsed: %f seconds\n", timeElapsed);
  exit(0);
}
