/*
 * Insertion Sort
 * Time Complexity: O(n^2)
 */

#include <iostream>

void insertion_sort(int arr[], int n)
{
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int arr[] = { 3, 1, 4, 64, 5, 9, 2, 6, 15, 31 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertion_sort(arr, n);
	std::cout << "Sorted array: ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
