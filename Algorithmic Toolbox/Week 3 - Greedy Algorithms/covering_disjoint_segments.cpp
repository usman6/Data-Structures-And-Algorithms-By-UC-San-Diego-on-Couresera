#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> FindOverlappingPoints(std::vector<std::pair<int, int>> coordinates) {
	std::vector<int> points;
	sort(coordinates.begin(), coordinates.end(), [](const auto & lhs, const auto & rhs) {
		return lhs.second < rhs.second;
	});

	int i = 0;
	while (i < coordinates.size()) {
		int index = i;
		while (i < coordinates.size() - 1 && coordinates[index].second >= coordinates[i + 1].first) {
			i++;
		}
		i++;
		points.push_back(coordinates[index].second);
	}


	return points;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> coordinates(n);
	for (int i = 0; i < n; i++) {
		int s1, s2;
		std::cin >> s1 >> s2;
		coordinates[i] = std::make_pair(s1, s2);
	}

	auto points = FindOverlappingPoints(coordinates);
	std::cout << points.size() << std::endl;
	for (int i = 0; i < points.size(); i++) {
		std::cout << points[i] << " ";
	}

	return 0;
}