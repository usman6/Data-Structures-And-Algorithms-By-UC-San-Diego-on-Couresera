#include<iostream>

int ComputeLastDigitOfNthFibonacci(int n) {
	int last_digit_fib_1 = 0;
	int last_digit_fib_2 = 1;

	for (int i = 2; i <= n; i++) {
		int tmp=last_digit_fib_2;
		last_digit_fib_2 = (last_digit_fib_1 + last_digit_fib_2) % 10;
		last_digit_fib_1 = tmp;
	}

	return last_digit_fib_2;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << ComputeLastDigitOfNthFibonacci(n) << std::endl;
	return 0;
}