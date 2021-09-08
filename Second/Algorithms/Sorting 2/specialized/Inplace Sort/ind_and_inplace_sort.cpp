#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int INSERTION_SORT_CUTOFF = 4;

template <typename T>
void insertion_sort_ind(std::vector<T>& v, std::vector<T*>& indirect) {
  int size = indirect.size();
  T* present_element = {};
  int new_spot = {};
  for (int i = 1; i < size; ++i) {
    present_element = indirect[i];
    for (int j = i - 1; j >= 0; --j) {
      if (*indirect[j] > *present_element) {
	indirect[j + 1] = indirect[j];
	if (!j) {
	  new_spot = 0;
	}
      }
      else {
	new_spot = j + 1;
	break;
      }
    }
    indirect[new_spot] = present_element;
  }
}

template <typename T>
inline void swap(T& first, T& second) {
  T temp = first;
  first = second;
  second = temp;
}

template <typename T>
int median_of_three(std::vector<T>& v, std::vector<T*>& indirect, int start, int end) {
  int mid = (start + end) / 2;
  if (v[mid] < v[start]) {
    swap(indirect[mid], indirect[start]);
  }
  if (v[end] < v[mid]) {
    swap(indirect[end], indirect[mid]);
  }
  if (v[mid] < v[start]) {
    swap(indirect[mid], indirect[start]);
  }
  return mid;
}

template <typename T>
void quick_sort_ind(std::vector<T>& v, std::vector<T*>& indirect, int start, int end) {
 beginning:
  if (end - start <= INSERTION_SORT_CUTOFF) {
    insertion_sort_ind(v, indirect);
    return;
  }
  int mid = median_of_three(v, indirect, start, end);
  swap(indirect[mid], indirect[end - 1]);
  int i = start, j = end - 1;
  while (i < j) {
    while (v[++i] < v[end]) {
      ;
    }
    while (v[--j] > v[end] and j > i) {
      ;
    }
    if (i < j) {
      swap(indirect[i], indirect[j]);
    }
  }
  swap(indirect[i], indirect[end - 1]);
  quick_sort_ind(v, indirect, start, i - 1);
  start = i + 1;
  goto beginning;
}

template <typename T>
void final_sort(std::vector<T>& v, std::vector<T*>& indirect) {
  int size = v.size();
  int index = {};
  for (int i = 0; i < size; ++i) {
    // indirect[i] - &v[0] is the index of the element
    // that indirect points to
    index = indirect[i] - &v[0];
    if (i == index) {
      continue;
    }
    int j = i;
    T val = v[i];    
    while (true) {
      int a = j;
      int k = indirect[a] - &v[0];      
      v[a] = v[k];
      j = k;
      indirect[a] = &v[a];
      if (indirect[j] - &v[0] == i) {
	v[j] = val;
	indirect[j] = &v[j];
	break;
      }
    }    
  }
}

template <typename T>
void quick_sort_ind(std::vector<T>& v, std::vector<T*>& indirect) {
  int size = v.size();
  quick_sort_ind(v, indirect, 0, size - 1);
}

int main(int argc, char* argv[]) {
  std::vector<int> v;
  for (int i = 0; i < 10; ++i) {
    unsigned int seed = i + time(NULL);
    srand(seed);
    v.push_back((rand() / 100) % 100);
  }
  int size = v.size();
  std::vector<int*> indirect(size, nullptr);
  for (int i = 0; i < size; ++i) {
    indirect[i] = &v[i];
  }
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  quick_sort_ind(v, indirect);  
  for (auto elem : indirect) {
    std::cout << *elem << " ";
  }
  std::cout << '\n';
  final_sort(v, indirect);
  for (auto elem : v) {
    std::cout << elem << " ";
  }  
  std::cout << '\n';
  return 0;
}
