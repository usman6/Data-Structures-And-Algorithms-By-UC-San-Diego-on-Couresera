#include<iostream>
#include<vector>

std::vector<int> ComputeMaximumNumberOfIntegersSumToValue(int n) {
	std::vector<int> integers;
	int i = 1;
	while (i + 1 <= n - i) {
		n -= i;
		integers.push_back(i);
		i++;
	}
	integers.push_back(n);
	return integers;
}

int main() {
	int n;
	std::cin >> n;
	auto integers = ComputeMaximumNumberOfIntegersSumToValue(n);
	std::cout << integers.size() << std::endl;
	for (auto num : integers) {
		std::cout << num << " ";
	}
	return 0;
}