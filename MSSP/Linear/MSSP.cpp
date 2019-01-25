#include <iostream>

int MSSP(int a[], int n, int& start_max, int& end_max);

int main(int argc, char* argv[]) {
  int a[] = {-10, 15, -10, 20, -50, 25, 10, -30, 15, -10, 40, -30, 20, -10,
	       5, -35, 20, -10, 15};
  int s = 0, e = 0;
  std::cout << MSSP(a, sizeof(a) / sizeof(int), s, e) << std::endl;
  std::cout << s << " " << e << std::endl;
  return 0;
}

int MSSP(int a[], int n, int& start_max, int& end_max) {
  // The minimum answer is 0
  int temp_sum = 0, max_sum = 0;
  // Start at the first index
  int temp_start = 0, temp_end = 0;
  // If these remain equal to -1 then the ideal subsequence is empty
  start_max = -1;
  end_max = -1;
  while (true) {
    for ( ; temp_sum >= 0 && temp_end < n; ++temp_end) { // >= ?
      // Add a new element
      temp_sum += a[temp_end];
      // New max sum
      if (temp_sum > max_sum) {
	// Record new max and start and end points
	max_sum = temp_sum;
	start_max = temp_start;
	end_max = temp_end;
      }
    }
    // Reached end of the array so finished
    if (temp_end == n) {
      return max_sum;
    }
    // If this is the case, including elements between temp_start
    // and temp_end is not ideal (gives a negative sum) so restart
    // problem with temp_start at temp_end and march forward
    if (temp_sum < 0) {
      temp_start = temp_end;
      temp_sum = 0;
    }
  }
}
