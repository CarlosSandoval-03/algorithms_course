/*
 * Is prime number
 * Time Complexity: O(sqrt(n))
 */

#include <iostream>

int main()
{
	int n = 1561;
	bool is_prime = false;
	if (n < 2) {
		is_prime = false;
	} else if (n % 2 == 0) {
		is_prime = false;
	} else {
		for (int i = 3; i * i <= n; i += 2) {
			if (n % i == 0) {
				is_prime = false;
				break;
			}
		}
		is_prime = true;
	}
	std::cout << is_prime << std::endl;
	return 0;
}
