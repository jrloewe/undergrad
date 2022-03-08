//  Jordan Drakos
//  CSCI 310 - Spring 2021
//  HW04 - print-data.c
//  The purpose of this program is to read from a file containing
//  n number of elements and print them out. It is intended to be used
//  in conjunction with generate-data.c, though this is not strictly
//  necessary.
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char** argv) {
  // This block keeps the user from using the program outside of its intended functionality.
  if (argc != 2) {
    printf("usage: ./print-data   <input file name>\n");
    exit(EXIT_FAILURE);
  }

  // Opens the file for reading. If the file doesn't exist, we need to print out
  // an error message to the terminal informing the user as such.
  FILE *fp = fopen(argv[1], "r");
  int errnum;
  if (fp == NULL) {
    errnum = errno;
    fprintf(stderr, "Error opening file \"%s\": %s\n", argv[1], strerror(errnum));
    exit(1);
  }

  int i, n;
  fread(&n, sizeof(int), 1, fp);

  // The file is looped through n number of times, based on how many elements there are,
  // and each one is printed on a new line.
  for (i = 0; i < n; i++) {
    int temp;
    fread(&temp, sizeof(int), 1, fp);
    printf("%d\n", temp);
  }

  // Since all work is done, the file should be closed.
  fclose(fp);
  exit(0);
}
