/*
 * Find all permutations of a set
 * Time Complexity: O(n!)
 */

#include <iostream>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

/**
 * Permutate the array (see like a tree)
 *  [1, 2, 3]
 *     Swap(0,0): [1, 2, 3]
 *       Swap(1, 1): [1, 2, 3]
 *       Swap(1, 2): [1, 3, 2]
 *
 *     Swap(0,1): [2, 1, 3]
 *       Swap(1, 1): [2, 1, 3]
 *       Swap(1, 2): [2, 3, 1]
 *
 *     Swap(0,2): [3, 2, 1]
 *       Swap(1, 1): [3, 2, 1]
 *       Swap(1, 2): [3, 1, 2]
 */
void permutate(int arr[], int s, int e)
{
	static int count = 0;
	if (arr == NULL && s == -1 && e == -1) {
		std::cout << "Total number of permutations: " << count << std::endl;
		return;
	}

	if (s == e) {
		for (int i = 0; i <= e; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		count++;
	} else {
		for (int i = s; i <= e; i++) {
			swap(arr[s], arr[i]);
			permutate(arr, s + 1, e);
			swap(arr[s], arr[i]);
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	permutate(arr, 0, n - 1);
	permutate(NULL, -1, -1); // Print the total number of permutations
	return 0;
}
