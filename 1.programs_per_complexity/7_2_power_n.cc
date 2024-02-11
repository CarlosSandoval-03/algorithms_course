/*
 * Find all subsets of a set
 * Time Complexity: O(2^n)
 */

#include <iostream>

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int count = 0;
	for (int i = 0; i < (1 << n); i++) {
		std::cout << "{ ";
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				std::cout << arr[j] << " ";
			}
		}
		std::cout << "}";
		std::cout << std::endl;
		count++;
	}

	std::cout << "Total subsets: " << count << std::endl;
	return 0;
}
