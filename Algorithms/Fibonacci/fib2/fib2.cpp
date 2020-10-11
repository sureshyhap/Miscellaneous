#include <iostream>

int fibonacci(int n);

int main(int argc, char* argv[]) {
  std::cout << fibonacci(5);
  return 0;
}

int fibonacci(int n) {
  if (n < 2) {
    return 1;
  }
  int first = 1;
  int second = 2;
  for (int x = 2; x < n; ++x) {
    int temp = first;
    first = second;
    second += temp;
  }
  return second;
}
