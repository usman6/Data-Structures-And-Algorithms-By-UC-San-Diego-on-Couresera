#include<iostream>
#include<tuple>

std::tuple<int, int> ThreeWayPartition(int arr[], int l, int r) {
	int x = arr[l];
	int j = l;
	int k = l;
	for (int i = l + 1; i <= r; i++) {
		if (x > arr[i]) {
			j++;
			std::swap(arr[j], arr[i]);
			k++;
			if (k != j && k != i) {
				std::swap(arr[k], arr[i]);
			}
		}
		else if (x == arr[i]) {
			k++;
			std::swap(arr[k], arr[i]);
		}
	}

	std::swap(arr[l], arr[j]);
	//std::cout << j << "," << k << "\n";
	return std::make_tuple(j, k);
	//special case
	//1 2 3 4 4 4 4 8 4
}

void ImprovedQuickSort(int arr[], int l, int r) {
	if (l >= r) {
		return;
	}
	int k = l + rand() % (r - l + 1);
	std::swap(arr[l], arr[k]);
	auto[m, n] = ThreeWayPartition(arr, l, r);
	ImprovedQuickSort(arr, l, m - 1);
	ImprovedQuickSort(arr, n + 1, r);
}

int main() {
	int n;
	std::cin >> n;
	int *arr;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	ImprovedQuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}