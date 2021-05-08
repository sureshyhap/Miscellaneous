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
void selection_sort(std::vector<T>& v) {
  int size = v.size();
  if (!size or size == 1) {
    return;
  }
  T min = {};
  for (int i = 0; i < size; ++i) {
    T min = v[i];
    int min_index = i;
    for (int j = i + 1; j < size; ++j) {
      if (v[j] < min) {
	min = v[j];
	min_index = j;
      }
    }
    swap(v[i], v[min_index]);
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
  selection_sort(v);
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  return 0;
}
