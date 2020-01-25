#include<iostream>

int ComputeNthFibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	int fib_1 = 0;
	int fib_2 = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = fib_2;
		fib_2 = fib_1 + fib_2;
		fib_1 = tmp;
	}

	return fib_2;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << ComputeNthFibonacci(n) << std::endl;
	return 0;
}