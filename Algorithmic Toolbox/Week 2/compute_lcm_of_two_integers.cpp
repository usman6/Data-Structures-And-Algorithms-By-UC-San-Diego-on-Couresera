#include<iostream>

int ComputeGcdOfTwoNumbers(int a, int b) {
	if (b == 0) {
		return a;
	}

	return ComputeGcdOfTwoNumbers(b, a%b);
}

long long ComputeLcmOfTwoIntegers(int a, int b) {
	int gcd = 0;
	if (a <= b) {
		gcd = ComputeGcdOfTwoNumbers(b, a);
	}
	else {
		gcd = ComputeGcdOfTwoNumbers(a, b);
	}

	return (long long)a *(b / gcd);
}

int main() {
	int a;
	int b;
	std::cin >> a;
	std::cin >> b;
	std::cout << ComputeLcmOfTwoIntegers(b, a) << std::endl;
	return 0;
}