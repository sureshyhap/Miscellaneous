#include <iostream>

const int QUICK_SORT_BASE = 20;

void quick_sort(int* p_a[], int start, int size);
void insertion_sort(int* p_a[], int start, int size);
void inplace_sort(int* p_a[], int a[], int size);

int main(int argc, char* argv[]) {
  int a[] = {44, 77, 55, 99, 66, 33, 22, 88, 77};
  int size = sizeof(a) / sizeof(int);
  int* p_a[size];
  for (int i = 0; i < size; ++i) {
    p_a[i] = &a[i];
  }
  quick_sort(p_a, 0, size);
  inplace_sort(p_a, a, size);
  
  for (int i = 0; i < size; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

void quick_sort(int* p_a[], int start, int size) {
 start:
  if (size < QUICK_SORT_BASE) {
    insertion_sort(p_a, start, size);
    return;
  }
  // int pivot = a[start + size - 1];
  // Median-of-three partitioning
  int left = start;
  int right = start +  size - 1;
  int median = (left + right) / 2;
  if (*p_a[left] > *p_a[median]) {
    int* temp = p_a[median];
    p_a[median] = p_a[left];
    p_a[left] = temp;
  }
  if (*p_a[right] < *p_a[median]) {
    int* temp = p_a[right];
    p_a[right] = p_a[median];
    p_a[median] = temp;
  }
  if (*p_a[left] > *p_a[median]) {
    int* temp = p_a[median];
    p_a[median] = p_a[left];
    p_a[left] = temp;
  }
  int* temp = p_a[median];
  p_a[median] = p_a[right - 1];
  p_a[right - 1] = temp;
  int* pivot = p_a[right - 1];
  int i = left + 1, j = right - 2;
  while (true) {
    while (*p_a[i] < *pivot) {
      ++i;
    }
    while (j >= i && *p_a[j] > *pivot) {
      --j;
    }
    if (i < j) {
      int* temp = p_a[i];
      p_a[i] = p_a[j];
      p_a[j] = temp;
    }
    else {
      p_a[right - 1] = p_a[i];
      p_a[i] = pivot;
      break;
    }
  }
  quick_sort(p_a, start, i - start);
  int s1 = start, s2 = size;
  start = i + 1;
  size = s1 + s2 - (i + 1);
  goto start;
}

void insertion_sort(int* p_a[], int start, int size) {
  for (int i = start + 1; i < start + size; ++i) {
    int* present_num = p_a[i];
    int j = i - 1;
    for (; j >= start; --j) {
      if (*present_num < *p_a[j]) {
	p_a[j + 1] = p_a[j];
      }
      else {
	p_a[j + 1] = present_num;
	goto end_first_loop;
      }
    }
    p_a[start] = present_num;
  end_first_loop:
    ;
  }
}

void inplace_sort(int* p_a[], int a[], int size) {
  for (int i = 0; i < size; ++i) {
    if (i == (p_a[i] - a)) {
      continue;
    }
    int j = i;
    int val = a[i];
    while (p_a[j] - a != i) {
      a[j] = *p_a[j];
      int k = j;
      j = p_a[j] - a;
      p_a[k] = a + k;
    }
    a[j] = val;
    p_a[j] = a + j;
  }
  return;
}
