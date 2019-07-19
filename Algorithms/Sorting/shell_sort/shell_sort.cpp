#include <iostream>

void shell_sort(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {37, 12, 75, 3, 74, 2, 4, 6, 6, 5, 34, 22, 11, 12, 13, 78, 90, 88};
  int n = sizeof(a) / sizeof(int);
  shell_sort(a, n);
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

void shell_sort(int a[], int n) {
  int d = 1;
  while (d < n / 6) {
    d = 3 * d + 1;
  }
  bool last_run = false;
  while (d > 0 || last_run == true) {
    for (int j = 0; j < d; ++j) {
      for (int i = d + j; i < n; i += d) {
	int val = a[i];
	int k = i;
	while (k - d >= 0 && val < a[k - d]) {
	  a[k] = a[k - d];
	  k -= d;
	}
	a[k] = val;
      }
    }
    d /= 3;
    if (last_run == true) {
      break;
    }
    if (d == 0 && last_run == false) {
      last_run = true;
      d = 1;
    }
    
  }
}
