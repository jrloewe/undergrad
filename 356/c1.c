#include<stdio.h>
void combine(int digit1, int digit2, int digit3, int *num, int *reversed_num) {
	// To combine the digits into entered order, multiply digit1 by 100,
	// digit2 by 10, then add these together with digit3.
	// To get the reversed number, follow the same idea, except digit1
	// and digit3 are swapped in the calculations.	
	*num = (digit1 * 100) + (digit2 * 10) + digit3;
	*reversed_num = (digit3 * 100) + (digit2 * 10) + digit1;
}

int main(int argc, char const *argv[]) {
	// Initialize our variables, then prompt the user to enter their digits.	
	int digit1, digit2, digit3, num, reversed_num;
	printf("Enter three digits separated by spaces: ");	
	scanf("%d %d %d", &digit1, &digit2, &digit3);

	// Prompt the user to re-enter their digits so long as
	// each digit is greater than 9.	
	while (digit1 > 9 || digit2 > 9 || digit3 > 9) {
		printf("Each digit should be less than 10.\n"
		"Enter three digits separated by spaces: ");
		scanf("%d %d %d", &digit1, &digit2, &digit3);	
	}
	
	// Call the combine function and print the results.
	combine(digit1, digit2, digit3, &num, &reversed_num);
	printf("After calling combine: \n"
	"Your number: 					%d\n"
	"Your number reversed:				%d\n", num, reversed_num);
	return 0;
}
