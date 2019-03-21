#include <iostream>

void quick_sort(int a[], int start, int size);

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
  if (size < 2) {
    return;
  }
  int pivot = a[start + size - 1];
  int i = start, j = start + size - 2;
  while (true) {
    while (a[i] < pivot) {
      ++i;
    }
    while (j >= 0 && a[j] > pivot) {
      --j;
    }
    if (i < j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    else {
      a[start + size - 1] = a[i];
      a[i] = pivot;
      break;
    }
  }
  quick_sort(a, start, i - start);
  quick_sort(a, i + 1, start + size - (i + 1));
}
