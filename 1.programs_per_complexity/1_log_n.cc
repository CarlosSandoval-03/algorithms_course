/*
 * Binary Search
 * Time Complexity: O(log n)
 * Requirements: The array must be sorted.
 */

#include <iostream>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 5;

	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			std::cout << "Found at index " << mid << std::endl;
			return 0;
		} else if (arr[mid] < x) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	std::cout << "Not found" << std::endl;
	return 0;
}
