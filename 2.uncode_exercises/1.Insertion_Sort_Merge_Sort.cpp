#include <bits/stdc++.h>

int insertion_sort(int arr[], int n)
{
	int comparations = 0;
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			++comparations;

			arr[j + 1] = arr[j];
			j--;
		}

		// If the last comparation was false, we still need to count it
		// as a comparation (only if j >= 0)
		if (j >= 0)
			++comparations;

		arr[j + 1] = key;
	}

	return comparations;
}

int merge(int arr[], int p, int q, int r)
{
	int comparations = 0;

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
		++comparations;
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

	return comparations;
}

int merge_sort(int arr[], int p, int r)
{
	if (p >= r) {
		return 0;
	}

	int q = (p + r) / 2;

	// Save the number of comparations
	int int_cpm1 = merge_sort(arr, p, q);
	int int_cpm2 = merge_sort(arr, q + 1, r);
	int comparations = merge(arr, p, q, r);

	// Return the sum of the comparations
	return int_cpm1 + int_cpm2 + comparations;
}

int main()
{
	// Read the number of elements
	int n = 0;
	std::cin >> n;

	// Create arrays and clear the array
	int arr[n], arr2[n];
	std::memset(arr, 0, sizeof(arr));
	std::memset(arr2, 0, sizeof(arr2));

	// Read input and store it in the array 1
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	// Copy the array 1 to the array 2
	std::memcpy(arr2, arr, sizeof(arr));

	// Array 1 - Insertion Sort
	int c1 = insertion_sort(arr, n);
	std::cout << c1 << std::endl;

	// Array 2 - Merge Sort
	int c2 = merge_sort(arr2, 0, n - 1);
	std::cout << c2 << std::endl;

	return 0;
}
