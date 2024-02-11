/*
 * Find index of a number in an array
 * Time Complexity: O(n)
 */

#include <iostream>

int main()
{
	int arr[] = { 3, 1, 4, 64, 5, 9, 2, 6, 15, 31 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 15;

	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			std::cout << "Found at index " << i << std::endl;
			return 0;
		}
	}
	std::cout << "Not found" << std::endl;
	return 0;
}
