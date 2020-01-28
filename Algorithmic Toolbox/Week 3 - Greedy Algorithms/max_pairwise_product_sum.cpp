#include<iostream>
#include<vector>
#include<algorithm>

long long MaxSumOfProducts(std::vector<int> & prices, std::vector<int>& clicks) {
	long long max_sum = 0;
	int size = clicks.size();

	sort(prices.begin(), prices.end());
	sort(clicks.begin(), clicks.end());

	for (int i = 0; i < size; i++) {
		max_sum = max_sum + (long long)prices[i] * clicks[i];
	}


	return max_sum;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> prices(n);
	std::vector<int> clicks(n);

	for (int i = 0; i < n; i++) {
		std::cin >> prices[i];
	}

	for (int i = 0; i < n; i++) {
		std::cin >> clicks[i];
	}

	std::cout << MaxSumOfProducts(prices, clicks) << std::endl;
	return 0;
}