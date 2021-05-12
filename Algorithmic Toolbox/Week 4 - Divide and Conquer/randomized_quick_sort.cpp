#include<iostream>

int Partition(int arr[], int l, int r) {
	int x = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (x >= arr[i]) {
			j++;
			std::swap(arr[j], arr[i]);
		}
	}

	std::swap(arr[l], arr[j]);
	return j;
}

void QuickSort(int arr[], int l, int r) {
	if (l >= r) {
		return;
	}
	int k = l + rand() % (r - l + 1);
	std::swap(arr[l], arr[k]);
	int m = Partition(arr, l, r);
	QuickSort(arr, l, m - 1);
	QuickSort(arr, m + 1, r);
}

int main() {
	int n;
	std::cin >> n;
	int *arr;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	QuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}