#include<iostream>

void Merge(int arr[], int f, int m, int l) {
	int n1 = m - f + 1;
	int n2 = l - (m + 1) + 1;
	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = f, j = 0; i <= m; i++, j++) {
		L[j] = arr[i];
	}

	for (int i = m + 1, j = 0; i <= l; i++, j++) {
		R[j] = arr[i];
	}

	int index = f, i = 0, j = 0;

	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			arr[index] = L[i];
			index++;
			i++;
		}
		else {
			arr[index] = R[j];
			index++;
			j++;
		}
	}

	while (i < n1) {
		arr[index] = L[i];
		index++;
		i++;
	}

	while (j < n2) {
		arr[index] = R[j];
		index++;
		j++;
	}

	delete[] L;
	delete[] R;
}

void MergeSort(int arr[], int f, int l) {
	int m = (l + f) / 2;
	if (f < l) {
		MergeSort(arr, f, m);
		MergeSort(arr, m + 1, l);
		Merge(arr, f, m, l);
	}

}

int main() {
	int n;
	std::cin >> n;
	int *arr;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	MergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}