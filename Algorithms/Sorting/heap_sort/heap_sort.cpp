#include <iostream>

void heap_sort(int a[], int n);
void heapify(int a[], int n, int k);

int main(int argc, char* argv[]) {
  int a[] = {345, 2548, 5434, 56, 234, 78, 6785, 345, 5636, 897, 345, 23, 786, 45, 35, 234, 765, 98, 7564};
  int n = sizeof(a) / sizeof(int);
  heap_sort(a, n);
  for (int i = 0l; i < n; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

void heap_sort(int a[], int n) {
  // Turning the array into a heap
  for (int i = (n / 2) - 1; i >= 0; --i) {
    heapify(a, n, i);
  }
  for (int i = n - 1; i > 0; --i) {
    int temp = a[i];
    a[i] = a[0];
    a[0] = temp;
    heapify(a, i, 0);
  }
}

void heapify(int a[], int n, int k) {
  // While k is not a leaf
  while (k < n / 2) {
    int child = (2 * k) + 1;
    // Get larger of two children to work with
    if (child + 1 < n && a[child + 1] > a[child]) {
      ++child;
    }
    if (a[k] > a[child]) {
      break;
    }
    else {
      int temp = a[k];
      a[k] = a[child];
      a[child] = temp;
      k = child;
    }
  }
}
