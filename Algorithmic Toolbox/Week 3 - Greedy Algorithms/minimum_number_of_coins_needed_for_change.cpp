#include<iostream>
#include<vector>

int FindMinimumNumberOfCoinsNeededForChange(int amount, const std::vector<int> & coinDenominationsSortedDesc) {
	int numCoins = 0;

	for (int i : coinDenominationsSortedDesc) {
		if (amount % i == 0) {
			return numCoins + amount / i;
		}
		else
		{
			numCoins = numCoins + amount / i;
			amount = amount - (amount / i) * i;
		}
	}

	return numCoins;
}

int main() {
	std::vector<int> denominations{ 10,5,1 };
	int amount;
	std::cin >> amount;
	std::cout << FindMinimumNumberOfCoinsNeededForChange(amount, denominations);
	return 0;
}