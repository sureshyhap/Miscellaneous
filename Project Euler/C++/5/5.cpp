#include <iostream>

int main(int argc, char* argv[]) {
  int num = 2520;
  while (true) {
  start_over:
    for (int i = 2; i <= 20; ++i) {
      if (num% i) {
	++num;
	goto start_over;
      }
    }
    std::cout <<  num << std::endl;
    return 0;
  }
  return 0;
}
