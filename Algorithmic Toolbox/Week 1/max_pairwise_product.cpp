#include<iostream>
#include<vector>

using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
	int index_1 = -1;
	for (int i = 0; i < numbers.size(); i++) {
		if (index_1 == -1 || numbers[i] > numbers[index_1]) {
			index_1 = i;
		}
	}

	int index_2 = -1;
	for (int i = 0; i < numbers.size(); i++) {
		if ((index_2 == -1 || numbers[i] > numbers[index_2]) && index_1 != i) {
			index_2 = i;
		}
	}

	return (long long)numbers[index_1] * numbers[index_2];
}

int main() {
	int size;
	cin >> size;
	vector<int> numbers(size);
	for (int i = 0; i < size; i++) {
		cin >> numbers[i];
	}

	cout << MaxPairwiseProduct(numbers);
	return 0;
}