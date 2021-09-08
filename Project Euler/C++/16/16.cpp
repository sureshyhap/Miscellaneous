#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
  long double two = pow(2, 1000);
  double digits = 1 + floor(1000 * log10(2));
  int sum = 0;
  for (int i = 1; i <= digits; ++i) {
    sum += two % int(pow(10, digits));
  }
  std::cout << sum;
  /*

  long double number = two / pow(10, digits);
  std::cout << number;
  *?
  return 0;
}
