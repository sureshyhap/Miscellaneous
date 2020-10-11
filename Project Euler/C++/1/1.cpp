#include <iostream>

int mult_3_5_sum(int bound);

int main(int argc, char* argv[]) {
  std::cout << mult_3_5_sum(1000) << '\n';
  return 0;
}

int mult_3_5_sum(int bound) {
  int sum = 0;
  for (int i = 1; i < bound; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}
