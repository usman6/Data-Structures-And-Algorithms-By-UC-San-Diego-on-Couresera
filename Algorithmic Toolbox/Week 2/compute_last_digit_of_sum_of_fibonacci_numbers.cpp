#include<iostream>

int ComputeLengthOfPisanoPeriodForFibonacciSum() {
	int a = 0, b = 1;
	int length = 0;
	int fibonacci_1 = 0, fibonacci_2 = 1;

	do {
		int fibonacci_3 = (fibonacci_1 + fibonacci_2) % 10;
		fibonacci_1 = fibonacci_2;
		fibonacci_2 = fibonacci_3;
		int temp = (fibonacci_2 + b) % 10;
		a = b;
		b = temp;
		length++;
	} while (!(a == 0 && b == 1));

	return length;
}

int FindLastDigitOfNthFibonacciSum(int n) {
	if (n == 0) {
		return 0;
	}
	int fib_1 = 0;
	int fib_2 = 1;
	int digit = 1;

	for (int i = 2; i <= n; i++) {
		int temp = (fib_1 + fib_2) % 10;
		fib_1 = fib_2;
		fib_2 = temp;
		digit = (digit + fib_2) % 10;
	}

	return digit;
}

int FindLastDigitOfNthFibonacciSum(long long n) {
	int pisano_length = ComputeLengthOfPisanoPeriodForFibonacciSum();

	int length = n % pisano_length;

	return FindLastDigitOfNthFibonacciSum(length);
}

int main() {
	long long n;
	std::cin >> n;
	std::cout << FindLastDigitOfNthFibonacciSum(n);
	return 0;
}