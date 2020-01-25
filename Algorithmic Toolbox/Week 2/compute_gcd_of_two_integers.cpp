#include<iostream>

int ComputeGcdOfTwoNumbers(int a, int b) {
	if (b == 0) {
		return a;
	}

	return ComputeGcdOfTwoNumbers(b, a%b);
}

int main() {
	int a;
	int b;
	std::cin >> a;
	std::cin >> b;
	if (a <= b) {
		std::cout << ComputeGcdOfTwoNumbers(b, a);
	}
	else {
		std::cout << ComputeGcdOfTwoNumbers(a, b);
	}
	return 0;
}