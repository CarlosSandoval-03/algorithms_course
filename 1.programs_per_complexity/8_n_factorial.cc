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
