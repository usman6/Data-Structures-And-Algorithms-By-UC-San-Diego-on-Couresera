#include<iostream>
#include<vector>
#include<limits>

int FindMinimumNumberOfCoins(int money, const std::vector<int> & denominations) {
	std::vector<int> min_coins(money + 1, std::numeric_limits<int>::max());
	min_coins[0] = 0;
	for (int m = 1; m <= money; m++) {
		for (int denomination : denominations) {
			if (m >= denomination) {
				int num_coins = min_coins[m - denomination] + 1;
				if (min_coins[m] > num_coins) {
					min_coins[m] = num_coins;
				}
			}
		}
	}
	return min_coins[money];
}

int main() {
	int money;
	std::vector<int> denominations = { 1,3,4 };
	std::cin >> money;
	std::cout << FindMinimumNumberOfCoins(money, denominations);
	return 0;
}