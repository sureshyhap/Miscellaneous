#include <iostream>

int MSSP(int a[], int n, int& start_max, int& end_max);

int main(int argc, char* argv[]) {
  int a[] = {-10, 15, -10, 20, -50, 25, 10, -30, 15, -10, 40, -30, 20,
	     -10, 5, -35, 20, -10, 15};
  int s = 0, e = 0;
  std::cout << MSSP(a, sizeof(a) / sizeof(int), s, e) << std::endl;
  std::cout << s << " " << e << std::endl;
  return 0;
}

int MSSP(int a[], int n, int& start_max, int& end_max) {
  int temp_sum = 0, max_sum = 0;
  start_max = -1;
  end_max = -1;
  // Brute force
  // Start at ith element
  for (int i = 0; i < n; ++i) {
    // End at jth element
    for (int j = i; j < n; ++j) {
      // Sum from ith element to jth element
      for (int k = i; k <= j; ++k) {
	temp_sum += a[k];
	if (temp_sum > max_sum) {
	  max_sum = temp_sum;
	  start_max = i;
	  end_max = j;
	}
      }
      temp_sum = 0;
    }
  }
  return max_sum;
}
