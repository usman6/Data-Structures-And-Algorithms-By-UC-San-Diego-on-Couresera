#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<algorithm>
#include<unordered_map>

int FindMaxAmountOfGoldWithoutRepeatingBars(int W, const std::vector<int> & bars) {
	std::vector<int> compute_arr(W + 1, 0);
	std::vector<std::unordered_map<int, int>> weight_arr(W + 1);
	std::unordered_map<int, int> bar_count;
	for (auto bar : bars) {
		if (bar_count.find(bar) == bar_count.end()) {
			bar_count[bar] = 1;
		}
		else {
			bar_count[bar] = bar_count[bar] + 1;
		}
	}
	weight_arr[0] = bar_count;
	for (int w = 1; w <= W; w++) {
		for (auto bar : bars) {
			if (bar <= w) {
				int value = compute_arr[w - bar] + bar;
				if (value > compute_arr[w] && weight_arr[w - bar][bar] > 0) {
					compute_arr[w] = value;
					std::unordered_map<int, int> n_bar_count(weight_arr[w - bar]);
					n_bar_count[bar] = n_bar_count[bar] - 1;
					weight_arr[w] = n_bar_count;
				}
			}
		}
		if (compute_arr[w] == 0) {
			compute_arr[w] = compute_arr[w - 1];
			std::unordered_map<int, int> n_bar_count(weight_arr[w - 1]);
			weight_arr[w] = n_bar_count;
		}
	}
	return compute_arr[W];
}


int main() {
	int W, n;
	std::cin >> W >> n;
	std::vector<int> bars(n, 0);
	for (auto &val : bars) {
		std::cin >> val;
	}

	std::cout << FindMaxAmountOfGoldWithoutRepeatingBars(W, bars);
	return 0;
}