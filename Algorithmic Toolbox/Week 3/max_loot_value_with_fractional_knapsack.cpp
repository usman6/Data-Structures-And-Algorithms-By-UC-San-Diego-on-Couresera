#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>

struct vault {
	int weight;
	int value;
	double value_by_weight;
};

bool CompareVaults(const vault &a, const vault &b) {
	return a.value_by_weight > b.value_by_weight;
}

double FindMaxValueForKnapsack(int n, int weight, const std::vector<vault> & vaults) {
	double value = 0;
	int capacity = weight;
	for (int i = 0; i < n && capacity > 0; i++) {
		if (vaults[i].weight <= capacity) {
			value = value + vaults[i].value;
			capacity = capacity - vaults[i].weight;
		}
		else {
			value = value + (double)capacity * vaults[i].value_by_weight;
			capacity = 0;
		}
	}
	return value;
}

int main() {
	int n = 0, W;
	std::cin >> n >> W;
	std::vector<vault> vaults(n);
	for (int i = 0; i < n; i++) {
		int weight, value;
		std::cin >> value >> weight;
		struct vault *v = new vault();
		v->value = value;
		v->weight = weight;
		v->value_by_weight = (double)value / weight;
		vaults.push_back(*v);
	}
	std::sort(vaults.begin(), vaults.end(), CompareVaults);
	/*
		for (vault v : vaults) {
			std::cout << v.value_by_weight << std::endl;
		}
	*/
	std::cout << std::fixed << FindMaxValueForKnapsack(n, W, vaults);
	return 0;
}