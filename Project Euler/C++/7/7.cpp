#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
  int i = 3;
  int prime = 1;
  while (true) {
    bool is_prime = true;
    for (int j = 2; j <= sqrt(i); ++j) {
      if (i % j == 0) {
	is_prime = false;
	break;
      }
    }
    if (is_prime) {
      ++prime;
    }
    if (prime == 10001) {
      break;
    }
    ++i;
  }
  std::cout << i;
  return 0;
}
