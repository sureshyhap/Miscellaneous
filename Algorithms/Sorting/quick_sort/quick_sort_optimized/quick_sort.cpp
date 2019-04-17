#include <iostream>

const int QUICK_SORT_BASE = 20;

void quick_sort(int a[], int start, int size);
void insertion_sort(int a[], int start, int size);

int main(int argc, char* argv[]) {
  int a[] = {44, 77, 55, 99, 66, 33, 22, 88, 77};
  int size = sizeof(a) / sizeof(int);
  quick_sort(a, 0, size);
  for (int i = 0; i < size; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

void quick_sort(int a[], int start, int size) {
 start:
  if (size < QUICK_SORT_BASE) {
    insertion_sort(a, start, size);
    return;
  }
  // int pivot = a[start + size - 1];
  // Median-of-three partitioning
  int left = start;
  int right = start +  size - 1;
  int median = (left + right) / 2;
  if (a[left] > a[median]) {
    int temp = a[median];
    a[median] = a[left];
    a[left] = temp;
  }
  if (a[right] < a[median]) {
    int temp = a[right];
    a[right] = a[median];
    a[median] = temp;
  }
  if (a[left] > a[median]) {
    int temp = a[median];
    a[median] = a[left];
    a[left] = temp;
  }
  int temp = a[median];
  a[median] = a[right - 1];
  a[right - 1] = temp;
  int pivot = a[right - 1];
  int i = left + 1, j = right - 2;
  while (true) {
    while (a[i] < pivot) {
      ++i;
    }
    while (j >= i && a[j] > pivot) {
      --j;
    }
    if (i < j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    else {
      a[right - 1] = a[i];
      a[i] = pivot;
      break;
    }
  }
  quick_sort(a, start, i - start);
  int s1 = start, s2 = size;
  start = i + 1;
  size = s1 + s2 - (i + 1);
  goto start;
}

void insertion_sort(int a[], int start, int size) {
  for (int i = start + 1; i < start + size; ++i) {
    int present_num = a[i];
    int j = i - 1;
    for (; j >= start; --j) {
      if (present_num < a[j]) {
	a[j + 1] = a[j];
      }
      else {
	a[j + 1] = present_num;
	goto end_first_loop;
      }
    }
    a[start] = present_num;
  end_first_loop:
    ;
  }
}
