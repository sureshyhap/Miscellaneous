#include <iostream>

void merge_sort(int a[], int start, int size);

int main(int argc, char* argv[]) {
  int a1[2] = {6, 3};
  int a2[3] = {2, 4, 1};
  int a3[4] = {5, 4, 2, 3};
  int a4[5] = {4, 7, 4, 56, 3};
  int a5[6] = {4, 7, 13, 4, 56, 3};

  merge_sort(a5, 0, 6);

  for (int i = 0; i < 6; ++i) {
    std::cout << a5[i] << " ";
  }
  
  return 0;
}

void merge_sort(int a[], int start, int size) {
  // Base case
  if (size == 1) {
    return;
  }

  // Dividing the problem into halves
  merge_sort(a, start, size / 2);
  merge_sort(a, start + (size / 2), size - (size / 2));

  // Merging
  int i = start, j = start + (size / 2), k = 0;
  int b[size] = {};
  while (i < start + (size / 2) && j < start + size) {
    if (a[i] > a[j]) {
      b[k] = a[j];
      ++j;
      ++k;
    }
    else {
      b[k] = a[i];
      ++i;
      ++k;
    }
  }
  if (i == start + (size / 2)) {
    while (j < start + size) {
      b[k] = a[j];
      ++j;
      ++k;
    }
  }
  else if (j == start + size) {
    while (i < start + (size / 2)) {
      b[k] = a[i];
      ++i;
      ++k;
    }
  }
  
  for (int count = 0; count < size; ++count) {
    a[start + count] = b[count];
  }
}
