#include <iostream>

// Assumes min number is 0
void counting_sort(int a[], int n, int max_num);

int main(int argc, char* argv[]) {
  int a[] = {7, 1, 3, 9, 5, 4, 6, 0, 4, 6, 2};
  int size = sizeof(a) / sizeof(int);
  counting_sort(a, size, 9);
  for (int i = 0; i < size; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

void counting_sort(int a[], int n, int max_num) {
  if (n < 1) {
    return;
  }
  int b[max_num + 1] = {0};
  for (int i = 0; i < n; ++i) {
    ++b[a[i]];
  }
  for (int i = 0, k = 0; i <= max_num; ++i) {
    for (int j = 0; j < b[i]; ++j) {
      a[k++] = i;
    }
  }
  return;
}
