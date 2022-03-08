#include<iostream>
using namespace std;

int main(int argc, char const* argv[]) {
  int A[] = { 4, 3, 6, 7, 10, 34, 9, -3, 4, 1 };

  for (int i = 1; i < 10; i++) {
    if (A[i] > A[i-1])
      cout << A[i] << " ";

    else
      cout << i << " ";
  }

  cout << "\n";
}
