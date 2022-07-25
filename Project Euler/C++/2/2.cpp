#include <iostream>

int even_fib_sum(int bound);

int main(int argc, char* argv[]) {
  std::cout << even_fib_sum(4e6) << '\n';
  return 0;
}

int even_fib_sum(int bound) {
  int first = 1, second = 2;
  // Sum so far is second because it is even
  int sum = second;
  for (int current = first + second; current < bound; current = first + second) {
    if (current % 2 == 0) {
      sum += current;
    }
    first = second;
    second = current;
  }
  return sum;;
}
