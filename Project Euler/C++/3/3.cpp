#include <iostream>
#include <cmath>

unsigned long biggest_prime_factor(unsigned long num);
bool check_prime(unsigned long num);

int main(int argc, char* argv[]) {
  std::cout << biggest_prime_factor(600851475143) << '\n';
  return 0;
}

unsigned long biggest_prime_factor(unsigned long num) {
  unsigned long small_factor = 2;
  unsigned long big_factor;
  while (true) {
    if (num % small_factor == 0) {
      big_factor = num / small_factor;
      if (check_prime(big_factor)) {
	return big_factor;
      }
    }
    ++small_factor;
  }
  /*
  unsigned long biggest = num - 1;
  while (true) {
    if (biggest == 1) {
      return 1;
    }
    if (num % biggest == 0) {
      if (check_prime(biggest)) {
	return biggest;
      }
    }
    --biggest;
  }
  */
}

bool check_prime(unsigned long num) {
  if (num % 2 == 0) {
    return false;
  }
  unsigned long factor = 3;
  unsigned long stop = sqrt(num);
  for (; factor <= stop; factor += 2) {
    if (num % factor == 0) {
      return false;
    }
  }
  return true;
}
