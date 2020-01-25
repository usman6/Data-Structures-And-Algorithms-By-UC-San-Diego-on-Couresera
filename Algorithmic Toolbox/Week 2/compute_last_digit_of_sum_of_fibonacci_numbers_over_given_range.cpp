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

int FindLastDigitOfNthFibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	int fib_1 = 0;
	int fib_2 = 1;

	for (int i = 2; i <= n; i++) {
		int temp = (fib_1 + fib_2) % 10;
		fib_1 = fib_2;
		fib_2 = temp;
	}

	return fib_2;
}

int FindLastDigitOfFibonacciSumOverGivenRange(int a, int b) {
	int diff = b - a;
	int fib_1 = FindLastDigitOfNthFibonacci(a);

	if (a == b) {
		return fib_1;
	}

	int fib_2 = FindLastDigitOfNthFibonacci(a + 1);

	int digit = (fib_1 + fib_2) % 10;

	for (int i = 1; i < diff; i++) {
		//std::cout << digit << std::endl;
		int temp = (fib_1 + fib_2) % 10;
		fib_1 = fib_2;
		fib_2 = temp;
		digit = (digit + fib_2) % 10;
	}

	return digit;
}

int main() {
	long long a, b;
	std::cin >> a >> b;
	int period = ComputeLengthOfPisanoPeriodForFibonacciSum();
	a = a % period;
	b = b % period;
	if (a <= b) {
		std::cout << FindLastDigitOfFibonacciSumOverGivenRange(a, b);
	}
	else {
		std::cout << FindLastDigitOfFibonacciSumOverGivenRange(a, b + 60);
	}
	return 0;
}