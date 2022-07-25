#include <iostream>
#include <vector>

int quick_select(std::vector<int> v, int left, int right, int k);

int main(int argc, char* argv[]) {
  std::vector<int> v{4, 10, 6, 8, 9, 12};
  std::cout << quick_select(v, 0, v.size() - 1, 5);

  return 0;
}

int quick_select(std::vector<int> v, int left, int right, int k) {
  if (right < left) {
    return int();
  }
  int mid;
  if (right - left >= 2) {
    mid = (left + right) / 2;
  }
  else {
    mid = right;
  }
  if (v[left] > v[mid]) {
    int temp = v[mid];
    v[mid] = v[left];
    v[left] = temp;
  }
  if (v[mid] > v[right]) {
    int temp = v[right];
    v[right] = v[mid];
    v[mid] = temp;
  }
  if (v[mid] < v[left]) {
    int temp = v[mid];
    v[mid] = v[left];
    v[left] = temp;
  }
  int med = v[mid];
  v[mid] = v[right];
  v[right] = med;
  int pivot = v[right];
  int i = left;
  int j = right - 1;
  while (true) {
    while (v[i] < pivot) {
      ++i;
    }
    while (v[j] > pivot && j >= i) {
      --j;
    }
    if (i < j) {
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
    }
    else {
      int temp = v[right];
      v[right] = v[i];
      v[i] = temp;
      break;
    }
  }
  // k is 1-indexed
  if (k - 1 == i) {
    return v[i];
  }
  else if (k - 1 < i) {
    return quick_select(v, left, i - 1, k);
  }
  else {
    return quick_select(v, i + 1, right, k);
  }
}
