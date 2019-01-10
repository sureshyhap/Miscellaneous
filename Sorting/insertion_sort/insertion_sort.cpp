#include <iostream>

void insertion_sort(int a[], int size);

int main(int argc, char* argv[]) {
  int a[] = {45, 7, 34, 89, 463, 7, 1, 3, 2, 100};
  insertion_sort(a, 10);
  for (int i = 0; i < 10; ++i) {
    std::cout << a[i] << " ";
  }
  
  return 0;
}

void insertion_sort(int a[], int size) {
  for (int i = 1; i < size; ++i) {
    int present_num = a[i];
    int j = i - 1;
    for (; j >= 0; --j) {
      if (present_num < a[j]) {
	a[j + 1] = a[j];
      }
      else {
	a[j + 1] = present_num;
	goto end_first_loop;
      }
    }
    a[0] = present_num;
  end_first_loop:
    ;
  }
}
