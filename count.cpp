#include <iostream>

void sort(std::vector<int> arr, int n) {
	int max{};
	for (int i = 0; i < n; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	std::vector<int> count(max,0);
	for (int i = 0; i < n; ++i) {
		++count[arr[i]];
	}
	for (int i = 1; i < max; ++i) {
		count[i] += count[i-1];
	}
	std::vector<int> res(n,0);
	for (int i = n - 1; i >= 0; --i) {
		res[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
}
