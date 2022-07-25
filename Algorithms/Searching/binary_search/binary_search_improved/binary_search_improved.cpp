#include <iostream>

int binary_search_improved(int a[], int size, int looking_for);

int main(int argc, char* argv[]) {
  int a[7] = {6, 8, 9, 10, 22, 36, 41};
  int b[6] = {6, 9, 9, 10, 22, 36};

  std::cout << binary_search_improved(a, 7, 22);
  
  return 0;
}

// Returns a -1 if the number is not in the array
// Returns the index of the number if it is in the array
// Warning as it is now it will just give any one of
// duplicate numbers if there are duplicates
int binary_search_improved(int a[], int size, int looking_for) {
  int low = 0, high = size - 1;
  while (high - low > 1) {
  
    if (a[(high + low) / 2] == looking_for) {
      return (high + low) / 2;
    }
    else if (a[(high + low) / 2] > looking_for) {
      high = ((high + low) / 2) - 1;
    }
    else if (a[(high + low) / 2] < looking_for) {
      low = ((high + low) / 2) + 1;
    }
  }
  
  if (low == high) {
    if (a[low] == looking_for) {
      return low;
    }
    else {
      return -1;
    }
  }
  
  if (low == high - 1) {
    if (a[low] == looking_for) {
      return low;
    }
    else if (a[high] == looking_for) {
      return high;
    }
    else {
      return -1;
    }
  }
}
