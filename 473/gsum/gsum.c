/* Jordan Drakos
 * CSCI 473 - GSUM
 * gsum.c - Handles MPI initialization and finalization, as well as calling the
 * global_sum function and printing the final sums of each node.
 * 26/02/2022 (created)
 * 06/03/2022 (last edited)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>
#include "functions.h"

int main(int argc, char *argv[]) {
  int rank, size, value;
  double sum;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  value = rank;

  // Print error message if the entered number of process is not a power of 2.
  if ((size & (size-1)) != 0) {
    // Only one process needs to print the error message.
    if (rank == 0) {
      printf("Number of processes must be a power of 2.\n");
    }

    exit(EXIT_FAILURE);
  }
  
  global_sum(&sum, rank, size, value);

  printf("FINAL IN MAIN: Process: %d has Sum = %f\n", rank, sum);

  MPI_Finalize();
  exit(0);
}//main
