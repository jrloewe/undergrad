/* Jordan Drakos
 * CSCI 473 - GSUM
 * functions.c - Defines function prototypes for program (currently consists
 * of only the global_sum function).
 * 26/02/2022 (created)
 * 06/03/2022 (last edited)
 */
 #include <stdio.h>
 #include <math.h>
 #include <mpi.h>
 #include "functions.h"

void global_sum(double* result, int rank, int size, double my_value) {
  // Set up initial mask.
  int mask = 1;
  int dest;
  // Buffer value for receiving from nodes.
  double buf;
  MPI_Status status;

  // Function should run for log base 2 size iterations.
  for (int i = 0; i < log2(size); ++i) {
    // XOR the rank and the mask to determine where values will be sent and received.
    dest = rank ^ mask;

    if (rank < dest) {
      printf("Phase (%d) - P%d sending (%.2f) to P%d\n", i, rank, my_value, dest);
      // Send the current value to the paired node.
      MPI_Ssend(&my_value, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
      printf("Phase (%d) - P%d receiving (%.2f) from P%d\n", i, dest, my_value, rank);
      // Receive the value from the paired node.
      MPI_Recv(&buf, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD, &status);
    }

    else {
      printf("Phase (%d) - P%d receiving (%.2f) from P%d\n", i, dest, my_value, rank);
      MPI_Recv(&buf, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD, &status);
      printf("Phase (%d) - P%d sending (%.2f) to P%d\n", i, rank, my_value, dest);
      MPI_Ssend(&my_value, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
    }

    // Add the received value to each node's current value.
    my_value += buf;

    // Shift the mask left 1.
    mask <<= 1;
  }

  // Calculate the sum from the total number of iterations.
  *result += my_value;
}//global_sum
