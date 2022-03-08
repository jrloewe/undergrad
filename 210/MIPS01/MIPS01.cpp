#include<iostream>
using namespace std;

int main(int argc, char const* argv[]) {
	int A[] = { 4, 3, 6, 7, 10, 34, 9, -3, 4, 1 };
	int i, sum = 0;

	for (i = 0; i < 10; i++) {
		sum += A[i];
	}

	cout << sum << "\n";
}
