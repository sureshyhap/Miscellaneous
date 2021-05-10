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
void quick_sort(std::vector<T>& v, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    swap(v[mid], v[end]);
    int i = start - 1, j = end;
    while (i < j) {
      while (v[++i] < v[end]) {
	;
      }
      while (v[--j] > v[end] and j > i) {
	;
      }
      if (i < j) {
	swap(v[i], v[j]);
      }
    }
    swap(v[i], v[end]);
    quick_sort(v, start, i - 1);
    quick_sort(v, i + 1, end);
  }
}

template <typename T>
void quick_sort(std::vector<T>& v) {
  int size = v.size();
  quick_sort(v, 0, size - 1);
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
  quick_sort(v);
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  return 0;
}
