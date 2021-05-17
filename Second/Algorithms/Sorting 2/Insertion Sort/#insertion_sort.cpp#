#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void insertion_sort(std::vector<T>& v) {
  int size = v.size();
  T present_element = {};
  int new_spot = {};
  for (int i = 1; i < size; ++i) {
    present_element = v[i];
    for (int j = i - 1; j >= 0; --j) {
      if (v[j] > present_element) {
	v[j + 1] = v[j];
	if (!j) {
	  new_spot = 0;
	}
      }
      else {
	new_spot = j + 1;
	break;
      }
    }
    v[new_spot] = present_element;
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> v;
  for (int i = 0; i < 25; ++i) {
    unsigned int seed = i + time(NULL);
    srand(seed);
    v.push_back((rand() / 100) % 20);
  }
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  insertion_sort(v);
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  return 0;
}
