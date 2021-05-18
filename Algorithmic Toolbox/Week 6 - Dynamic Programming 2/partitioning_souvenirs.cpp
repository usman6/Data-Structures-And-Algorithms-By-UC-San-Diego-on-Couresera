#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<algorithm>
#include<unordered_map>

int PartitionSouvenirs(const std::vector<int> & souvenirs, int n) {
	int total = 0;
	if (n < 3) {
		return 0;
	}
	for (auto souvenir : souvenirs) {
		total += souvenir;
	}
	if (total % 3 != 0) {
		return 0;
	}

	std::vector<int> compute_arr(total + 1, 0);
	std::vector<std::unordered_map<int, int>> souvenir_arr(total + 1);
	std::unordered_map<int, int> souvenir_count;
	for (auto souvenir : souvenirs) {
		if (souvenir_count.find(souvenir) == souvenir_count.end()) {
			souvenir_count[souvenir] = 1;
		}
		else {
			souvenir_count[souvenir] = souvenir_count[souvenir] + 1;
		}
	}
	souvenir_arr[0] = souvenir_count;
	for (int s = 1; s <= total; s++) {
		for (auto souvenir : souvenirs) {
			if (souvenir <= s) {
				int value = compute_arr[s - souvenir] + souvenir;
				if (value > compute_arr[s] && souvenir_arr[s - souvenir][souvenir] > 0) {
					compute_arr[s] = value;
					std::unordered_map<int, int> n_souvenir_count(souvenir_arr[s - souvenir]);
					n_souvenir_count[souvenir] = n_souvenir_count[souvenir] - 1;
					souvenir_arr[s] = n_souvenir_count;
				}
			}
		}
		if (compute_arr[s] == 0) {
			compute_arr[s] = compute_arr[s - 1];
			std::unordered_map<int, int> n_souvenir_count(souvenir_arr[s - 1]);
			souvenir_arr[s] = n_souvenir_count;
		}
	}

	for (auto & it : souvenir_arr[total]) {
		if (it.second > 0) {
			return 0;
		}
	}
	int p1 = total / 3, p2 = p1 * 2, p3 = p1 * 3;
	if (compute_arr[p1] == p1 && compute_arr[p2] == p2 && compute_arr[p3] == p3) {
		return 1;
	}

	return 0;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<int> souvenirs(n, 0);
	for (auto &val : souvenirs) {
		std::cin >> val;
	}

	std::cout << PartitionSouvenirs(souvenirs, n);
	return 0;
}