/* Jordan Drakos
 * CSCI 473 - Leibniz Pi OpenMP
 * pi_parallel.c - Calculates the value of pi using the Leibniz formula based on
 *                 the number of user-specified threads. Unlike pi_serial, it
 *                 uses OpenMP to parallelize the work across multiple threads.
 * 11/02/2022 (created)
 * 13/02/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main (int argc, char* argv[]) {
  // Declare the variables used in the course of the program. The sum variable must
  // be initialized to 0 to avoid any warning during compiling, though it should
  // still work.
  double pi, sum = 0;
  int numThreads;
  unsigned long int numTerms;

  // Print a usage statement if the argument count is more or less than three (3).
  if (argc != 3) {
    printf("Usage: %s <number of terms> <number of threads>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  numTerms = atoi(argv[1]);
  if (numTerms < 1) {
    printf("Number of terms should be a positive non-zero number.\n");
    exit(EXIT_FAILURE);
  }

  // Make certain that the user is not able to attempt running it on less than one
  // thread. While the idea of a single thread runs somewhat counter to the idea
  // of parallelizing the program, it's still a viable thread number.
  numThreads = atoi(argv[2]);
  if (numThreads < 1) {
    printf("Program requires at least one thread.\n");
    exit(EXIT_FAILURE);
  }

  // Get the time just before any operations are performed.
  double start = omp_get_wtime();

  // Use OMP to set the user-specified number of threads.
  omp_set_num_threads(numThreads);

  // Use OMP to parallelize the summation work across the number of threads,
  // using reduction to keep the sum variable from being updated improperly.
  #pragma omp parallel for reduction(+:sum)
  for (unsigned long int k = 0; k < numTerms; ++k) {
    sum+= pow(-1, k) / (2 * k + 1);
  }

  // Calculate the value of pi and the time elapsed after all operations are complete.
  pi = 4 * sum;
  double timeElapsed = omp_get_wtime() - start;

  // Print the value of pi, the number of threads, and time elapsed to the screen.
  printf("Value of pi based on %lu terms and %d threads: %.17f\n", numTerms, numThreads, pi);
  printf("Time elapsed: %f seconds\n", timeElapsed);
  exit(0);
}
