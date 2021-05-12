#include<iostream>
#include<vector>
#include<limits>

std::vector<std::vector<int>> FindMinimumNumberOfOperations(int number, std::vector<std::vector<int>> &computeArr) {
	computeArr[0][number] = 0;
	for (int m = number; m >= 1; m--) {
		if (m % 3 == 0) {
			int res = m / 3;
			int min = computeArr[0][m] + 1;
			if (min < computeArr[0][res]) {
				computeArr[0][res] = min;
				computeArr[1][res] = 3;
			}
		}
		if (m % 2 == 0) {
			int res = m / 2;
			int min = computeArr[0][m] + 1;
			if (min < computeArr[0][res]) {
				computeArr[0][res] = min;
				computeArr[1][res] = 2;
			}
		}
		if (m - 1 > 0) {
			int res = m - 1;
			int min = computeArr[0][m] + 1;
			if (min < computeArr[0][res]) {
				computeArr[0][res] = min;
				computeArr[1][res] = 1;
			}
		}
	}
	return computeArr;
}


int main() {
	int number = 0;
	std::cin >> number;
	std::vector<std::vector<int>> computeArr(2, std::vector<int>(number + 1, std::numeric_limits<int>::max()));
	FindMinimumNumberOfOperations(number, computeArr);
	std::cout << computeArr[0][1] << std::endl;
	int num = 1;
	while (num < number) {
		int next = computeArr[1][num];
		std::cout << num << " ";
		if (next == 1) {
			num = next + num;
		}
		else {
			num = next * num;
		}
	}
	std::cout << number << std::endl;

	return 0;
}