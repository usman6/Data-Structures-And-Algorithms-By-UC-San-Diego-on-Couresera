#include<iostream>

int ComputeLengthOfPisanoPeriod(int modulo) {
	int a = 0, b = 1;
	int length = 0;

	do {
		int temp = (a + b) % modulo;
		a = b;
		b = temp;
		length++;
	} while (!(a == 0 && b == 1));

	return length;
}

long long ComputeModuloOfNthFibonacci(int n, int modulo) {
	if (n == 0) {
		return 0;
	}

	long long fib_1 = 0;
	long long fib_2 = 1;

	for (int i = 2; i <= n; i++) {
		long long tmp = fib_2;
		fib_2 = (fib_1 + fib_2) % modulo;
		fib_1 = tmp;
	}

	return fib_2;
}


int ComputeModuloOfHugeFibonacci(long long n, int modulo) {
	int length_of_pisano_period = ComputeLengthOfPisanoPeriod(modulo);
	//std::cout << "length of pisano period: " << length_of_pisano_period << std::endl;
	int remainder = n % (long long)length_of_pisano_period;
	return ComputeModuloOfNthFibonacci(remainder, modulo);
}

int main() {
	long long n;
	int m;
	std::cin >> n >> m;
	std::cout << ComputeModuloOfHugeFibonacci(n, m) << std::endl;
	return 0;
}