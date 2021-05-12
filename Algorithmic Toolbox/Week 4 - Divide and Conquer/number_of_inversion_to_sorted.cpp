#include<iostream>

int MergeAndCountInversions(int arr[], int f, int m, int l) {
	int n1 = m - f + 1;
	int n2 = l - (m + 1) + 1;
	int *L = new int[n1];
	int *R = new int[n2];

	int inversions = 0;

	for (int i = f, j = 0; i <= m; i++, j++) {
		L[j] = arr[i];
	}

	for (int i = m + 1, j = 0; i <= l; i++, j++) {
		R[j] = arr[i];
	}

	int index = f, i = 0, j = 0;

	while (i < n1 && j < n2) {
		if (L[i] == R[j]) {
			arr[index] = L[i];
			index++;
			i++;
		}
		else if (L[i] < R[j]) {
			arr[index] = L[i];
			index++;
			i++;
		}
		else {
			arr[index] = R[j];
			index++;
			j++;
			inversions = inversions + (n1 - i);
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
	return inversions;
}

int FindInversionsToSorted(int arr[], int f, int l) {
	int m = (l + f) / 2;
	int a = 0, b = 0;
	if (f < l) {
		a = FindInversionsToSorted(arr, f, m);
		b = FindInversionsToSorted(arr, m + 1, l);
		return MergeAndCountInversions(arr, f, m, l) + a + b;
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	int i = FindInversionsToSorted(arr, 0, n - 1);
	std::cout << i << std::endl;
	return 0;
}