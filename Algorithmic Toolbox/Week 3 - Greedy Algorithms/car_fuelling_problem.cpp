#include<iostream>
#include<vector>
#include<string>
#include<sstream>

int FindMinimumNumberOfRefuels(int d, int m, int n, const std::vector<int>& stops) {
	if (d <= m) {
		return 0;
	}
	if (d - stops[n - 1] > m || stops[0] > m) {
		return -1;
	}
	int min_stops = 0;
	int current_distance = 0;
	int i = 0;
	while (i < n && current_distance < d && current_distance != stops[n - 1] && d - current_distance > m) {
		while (i < n && (stops[i] - current_distance) <= m) {
			i++;
		}
		i--;
		if (i < n - 1 && stops[i + 1] - stops[i] > m) {
			return -1;
		}
		current_distance = stops[i];
		min_stops++;
	}
	return min_stops;
}

int main() {
	int d, m, n;
	std::cin >> d;
	std::cin >> m;
	std::cin >> n;
	std::vector<int> stops(n);

	for (int i = 0; i < n; i++) {
		std::cin >> stops[i];
	}

	std::cout << FindMinimumNumberOfRefuels(d, m, n, stops);
	return 0;
}