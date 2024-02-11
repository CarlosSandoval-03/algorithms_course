/*
 * Merge Sort
 * Time Complexity: O(n log n)
 */

#include <iostream>

void merge(int arr[], int p, int q, int r)
{
	int nl = q - p + 1, nr = r - q;
	int L[nl], R[nr];
	for (int i = 0; i < nl; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < nr; j++) {
		R[j] = arr[q + j + 1];
	}

	int i = 0, j = 0, k = p;
	while (i < nl && j < nr) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < nl) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < nr) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

int merge_sort(int arr[], int p, int r)
{
	if (p >= r) {
		return -1;
	}

	int q = (p + r) / 2;
	merge_sort(arr, p, q);
	merge_sort(arr, q + 1, r);

	merge(arr, p, q, r);
	return 0;
}

int main()
{
	int arr[] = { 3, 1, 4, 64, 5, 9, 2, 6, 15, 31 };
	int n = sizeof(arr) / sizeof(arr[0]);

	merge_sort(arr, 0, n - 1);
	std::cout << "Sorted array: ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
