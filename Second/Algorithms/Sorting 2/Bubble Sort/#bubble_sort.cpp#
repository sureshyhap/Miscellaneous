#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
inline void swap(T& first, T& second) {
  T temp = first;
  first = second;
  second = temp;
}

template <typename T>
void bubble_sort(std::vector<T>& v) {
  int size = v.size();
  bool swapped = false;
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - 1 - i; ++j) {
      if (v[j] > v[j + 1]) {
	swap(v[j], v[j + 1]);
	swapped = true;
      }
    }
    // No swaps on a pass through the elements
    // means it is sorted already
    if (!swapped) {
      return;
    }
    else {
      swapped = false;
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> v;
  for (int i = 0; i < 25; ++i) {
    unsigned int seed = i + time(NULL);
    srand(seed);
    v.push_back(rand() % 20);
  }
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  bubble_sort(v);
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  return 0;
}
