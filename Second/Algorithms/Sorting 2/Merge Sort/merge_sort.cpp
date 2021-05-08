#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void merge_sort(std::vector<T>& v, std::vector<T>& temp, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    merge_sort(v, temp, start, mid);
    merge_sort(v, temp, mid + 1, end);
    int i = start, j = mid + 1, k = start;
    while (i <= mid and j <= end) {
      while (v[i] <= v[j]) {
	temp[k++] = v[i++];
	if (i > mid) {
	  goto outside;
	}
      }
      while (v[i] > v[j]) {
	temp[k++] = v[j++];
	if (j > end) {
	  goto outside;
	}
      }
    }
  outside:
    while (j <= end) {
      temp[k++] = v[j++];
    }
    while (i <= mid) {
      temp[k++] = v[i++];
    }
    for (int a = start; a <= end; ++a) {
      v[a] = temp[a];
    }    
  }
}

template <typename T>
void merge_sort(std::vector<T>& v) {
  int size = v.size();
  std::vector<T> temp(size);
  merge_sort(v, temp, 0, size - 1);
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
  merge_sort(v);
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  return 0;
}
