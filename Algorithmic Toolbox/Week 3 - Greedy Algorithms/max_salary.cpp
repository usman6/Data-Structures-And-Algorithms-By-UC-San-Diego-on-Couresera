#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

std::vector<std::string> ComputeMaxNumberFromDigits(std::vector<std::string> numbers) {
	sort(numbers.begin(), numbers.end(), [](const std::string lhs, const std::string rhs) {
		int res1 = stoi(lhs + rhs);
		int res2 = stoi(rhs + lhs);
		if (res1 > res2) {
			return true;
		}
		return false;
	});
	return numbers;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> numbers(n);
	for (int i = 0; i < n; i++) {
		std::cin >> numbers[i];
	}
	for (auto num : ComputeMaxNumberFromDigits(numbers)) {
		std::cout << num;
	}
	return 0;
}