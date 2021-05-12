#include<iostream>
#include<vector>

int BinarySearch(int element, int start, int end, const std::vector<int> & sorted_arr) {
	if (start == end && sorted_arr[start] == element) {
		return start;
	}
	if (start >= end) {
		return -1;
	}

	int middle = (start + end) / 2;
	if (sorted_arr[middle] == element) {
		return middle;
	}
	else if (sorted_arr[middle] > element) {
		return BinarySearch(element, start, middle - 1, sorted_arr);
	}
	else {
		return BinarySearch(element, middle + 1, end, sorted_arr);
	}
}

int main() {
	int n, k;
	std::cin >> n;
	std::vector<int> sorted_arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> sorted_arr[i];
	}
	std::cin >> k;
	std::vector<int> searches(k);
	for (int i = 0; i < k; i++) {
		std::cin >> searches[i];
	}
	for (auto i : searches) {
		std::cout << BinarySearch(i, 0, n-1, sorted_arr) << " ";
	}
	return 0;
}