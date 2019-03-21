#include <iostream>

void selection_sort(int a[], int size);

int main(int argc, char* argv[]) {
  int a[] = {83, 823, 365, 8274, 05, 4, 84074, 679};
  selection_sort(a, 8);
  for (int i = 0; i < 8; ++i) {
    std::cout << a[i] << " ";
  }
  
  return 0;
}

void selection_sort(int a[], int size) {
  for (int j = 0; j < size; ++j) {
    int i = 0, max = a[0], max_index = 0;    
    for (; i < size - j; ++i) {
      if (a[i] > max) {
	max = a[i];
	max_index = i;
      }
    }
    a[max_index] = a[--i];
    a[i] = max;
  }
}
