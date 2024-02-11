/*
 * Solve 3 variables equation
 * Time Complexity: O(n^3)
 */

#include <iostream>
#include <vector>

int main() {
  std::vector<int> solutions;

  for (int x = 0; x <= 100; x++) {
    for (int y = 0; y <= 100; y++) {
      for (int z = 0; z <= 100; z++) {
        if (2 * x + 3 * y + 4 * z == 100) {
          solutions.push_back(x);
          solutions.push_back(y);
          solutions.push_back(z);
        }
      }
    }
  }

  for (int i = 0; i < solutions.size(); i += 3) {
    std::cout << "x: " << solutions[i] << ", y: " << solutions[i + 1] << ", z: " << solutions[i + 2] << std::endl;
  }
  return 0;
}
