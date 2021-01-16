#include <iostream>

bool check_pythagoras(int a, int b, int c);

int main(int argc, char* argv[]) {
  const int sum = 1000;
  for (int a = 1; a <= sum - 2; ++a) {
    for (int b = a + 1; b <= sum - 1; ++b) {
      int c = sum - a - b;
      if (check_pythagoras(a, b, c)) {
	std::cout << a * b * c;
	return 0;
      }
    }
  }  
  return 0;
}

bool check_pythagoras(int a, int b, int c) {
  if (a * a + b * b == c * c) {
    return true;
  }
  else {
    return false;
  }
}
