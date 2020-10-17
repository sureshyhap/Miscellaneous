#include <iostream>

// Need to find a way to track start and end //////////////////////////////
int MSSP(int a[], int beginning, int n, int& start_max, int& end_max);

int main(int argc, char* argv[]) {
  int a[] = {-10, 15, -10, 20, -50, 25, 10, -30, 15, -10, 40, -30, 20,
	     -10, 5, -35, 20, -10, 15};
  int s = 0, e = 0;
  std::cout << MSSP(a, 0, sizeof(a) / sizeof(int), s, e) << std::endl;
  std::cout << s << " " << e << std::endl;
  return 0;
}

int MSSP(int a[], int beginning, int n, int& start_max, int& end_max) {
  // I don't think this check is necessary
  /* 
  if (n == 0) {
    return 0;
  }
  */
  if (n == 1) {
    // If single element is negative don't include it
    if (a[beginning] < 0) {
      return 0;
    }
    else {
      // Otherwise include it
      return a[beginning];
    }
  }
  // Subsequence is either completely to the left of the middle,
  int left = MSSP(a, beginning, n / 2, start_max, end_max);
  // to the right of the middle,
  int right = MSSP(a, beginning + (n / 2), n - (n / 2), start_max, end_max);
  // or through the middle
  int mid_right = beginning + (n / 2);
  int mid_left = mid_right - 1;
  // If it is through the middle it must contain these elements
  int temp_sum = a[mid_right] + a[mid_left];
  int max_sum = temp_sum;
  // March backwards from middle to find largest sum there
  for (int i = mid_left - 1; i >= beginning; --i) {
    temp_sum += a[i];
    if (temp_sum > max_sum) {
      max_sum = temp_sum;
    }
  }
  temp_sum = max_sum;
  // March forwards from middle to find largest sum
  for (int j = mid_right + 1; j < beginning + n; ++j) {
    temp_sum += a[j];
    if (temp_sum > max_sum) {
      max_sum = temp_sum;
    }
  }
  // Return maximum of the three sums
  if (left < right) {
    if (right < max_sum) {
      return max_sum;
    }
    else {
      return right;
    }
  }
  if (left > right) {
    if (left < max_sum) {
      return max_sum;
    }
    else {
      return left;
    }
  }
}
