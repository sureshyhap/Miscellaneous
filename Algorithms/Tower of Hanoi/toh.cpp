#include <iostream>

void toh(int num_rings, char source, char auxiliary, char destination);

void toh(int num_rings, char source, char auxiliary, char destination) {
  if (num_rings == 0) {
    return;
  }
  toh(num_rings - 1, source, destination, auxiliary);
  std::cout << "Move top ring from " << source << " to " << destination << '\n';
  toh(num_rings - 1, auxiliary, source, destination);
}

int main(int argc, char* argv[]) {
  toh(4, 'A', 'B', 'C');
}
