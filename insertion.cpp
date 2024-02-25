// C++ program for insertion sort

#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key, 
		// to one position ahead of their
		// current position
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	auto start_time = std::chrono::high_resolution_clock::now();
	int arr[] = { 12, 11, 7, 13, 5, 6 ,7,34,23,98,11,32,2,5,15,16,123,53,23,232,3424,543,25,423,454,23,4,45,53,2,34,5,231,54,2,12,3};
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);
	auto end_time =  std::chrono::high_resolution_clock::now();
	auto execution_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
	std::cout << execution_time.count() << " " << N << std::endl;
	return 0;
}
// This is code is contributed by rathbhupendra

