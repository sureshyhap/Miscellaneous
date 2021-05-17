#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int INSERTION_SORT_CUTOFF = 4;

template <typename T>
void insertion_sort(std::vector<T>& v);

template <typename T>
inline void swap(T& first, T& second) {
  T temp = first;
  first = second;
  second = temp;
}

template <typename T>
int median_of_three(std::vector<T>& v, int start, int end) {
  int mid = (start + end) / 2;
  if (v[mid] < v[start]) {
    swap(v[mid], v[start]);
  }
  if (v[end] < v[mid]) {
    swap(v[end], v[mid]);
  }
  if (v[mid] < v[start]) {
    swap(v[mid], v[start]);
  }
  return mid;
}

template <typename T>
void quick_sort(std::vector<T>& v, int start, int end) {
 beginning:
  if (end - start <= INSERTION_SORT_CUTOFF) {
    insertion_sort(v);
    return;
  }
  int mid = median_of_three(v, start, end);
  swap(v[mid], v[end - 1]);
  int i = start, j = end - 1;
  while (i < j) {
    while (v[++i] < v[end - 1]) {
      ;
    }
    while (v[--j] > v[end - 1] and j > i) {
      ;
    }
    if (i < j) {
      swap(v[i], v[j]);
    }
  }
  swap(v[i], v[end - 1]);
  quick_sort(v, start, i - 1);
  start = i + 1;
  goto beginning;
}

template <typename T>
void quick_sort(std::vector<T>& v) {
  int size = v.size();
  quick_sort(v, 0, size - 1);
}

int main(int argc, char* argv[]) {
  std::vector<int> v;
  for (int i = 0; i < 50; ++i) {
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
