//  Jordan Drakos
//  CSCI 310 - Spring 2021
//  HW04 - generate-data.c
//  The purpose of this program is to write to n number of
//  random elements to use in conjunction with the
//  accompanying print-data.c.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char** argv) {
  // This block keeps the user from using the program outside of its intended functionality.
  if (argc != 3) {
    printf("usage: ./generate-data    <n -- number of items>    <output file name>\n");
    exit(EXIT_FAILURE);
  }

  // Opens the specified file for writing.
  FILE *fp = fopen(argv[2], "w");

  // Since n is read in as a char, it must be converted to int. We also need to seed
  // using srand48 so we don't end up with the same numbers every time data is generated.
  int i, n;
  n = atoi(argv[1]);
  srand48(time(NULL));

  // To fill in the n-sized data elements, we need to loop through n times and generate
  // a random number in each iteration using mrand48 and write it to the file.
  fwrite(&n, sizeof(int), 1, fp);
  for (i = 0; i < n; i++) {
    int temp = mrand48();
    fwrite(&temp, sizeof(int), 1, fp);
  }

  // Since all work is done, the file should be closed.
  fclose(fp);
  exit(0);
}
