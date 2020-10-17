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
  return fibonacci(n - 1) + fibonacci(n - 2);
}
