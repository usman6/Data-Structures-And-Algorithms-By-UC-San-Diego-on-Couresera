#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<algorithm>

int ComputeEditDistance(std::string s1, std::string s2) {
	std::vector<std::vector<int>> computeArr(s1.length() + 1, std::vector<int>(s2.length() + 1, 0));
	for (int i = 0; i <= s2.length(); i++) {
		computeArr[0][i] = i;
	}
	for (int i = 0; i <= s1.length(); i++) {
		computeArr[i][0] = i;
	}
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s2[j - 1] == s1[i - 1]) {
				computeArr[i][j] = std::min(computeArr[i][j - 1] + 1, std::min(computeArr[i - 1][j] + 1, computeArr[i - 1][j - 1]));
			}
			else
			{
				computeArr[i][j] = std::min(computeArr[i][j - 1] + 1, std::min(computeArr[i - 1][j] + 1, computeArr[i - 1][j - 1] + 1));
			}
		}
	}
	return computeArr[s1.length()][s2.length()];
}


int main() {
	std::string s1, s2;
	std::cin >> s1;
	std::cin >> s2;
	std::cout << ComputeEditDistance(s1, s2);
	return 0;
}