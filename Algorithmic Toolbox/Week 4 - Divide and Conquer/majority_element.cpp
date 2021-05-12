#include<iostream>


int FindMajorityElement(int arr[], int l, int r) {

	if (l == r) {
		return arr[l];
	}

	int m = l + (r - l) / 2;
	int a = FindMajorityElement(arr, l, m);
	int b = FindMajorityElement(arr, m + 1, r);

	int half = (r - l + 1) / 2 + 1;
	int count = 0;
	if (a != -1) {
		for (int i = l; i <= r; i++) {
			if (a == arr[i]) {
				count++;
			}
		}
		if (count >= half) {
			return a;
		}
	}

	count = 0;
	if (b != -1) {
		for (int i = l; i <= r; i++) {
			if (b == arr[i]) {
				count++;
			}
		}
		if (count >= half) {
			return b;
		}
	}

	return -1;
}

int main() {
	int n, *arr;
	std::cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	int majority_element = FindMajorityElement(arr, 0, n - 1);
	int exists = 0;
	delete[] arr;
	if (majority_element != -1) {
		exists = 1;
	}
	std::cout << exists;
	return 0;
}