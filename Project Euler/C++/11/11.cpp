#include <iostream>
#include <fstream>

const int dimensions = 20;
const int adjacent = 4;

int check_horizontal(int a[][dimensions]);
int check_vertical(int a[][dimensions]);
int check_left_right_diagonal(int a[][dimensions]);
int check_right_left_diagonal(int a[][dimensions]);

int main(int argc, char* argv[]) {
  std::ifstream infile("grid.txt");
  int grid[dimensions][dimensions] = {{0}};
  for (int i = 0; i < dimensions; ++i) {
    for (int j = 0; j < dimensions; ++j) {
      infile >> grid[i][j];
    }
  }
  int max1 = check_horizontal(grid);
  int max2 = check_vertical(grid);
  int max3 = check_left_right_diagonal(grid);
  int max4 = check_right_left_diagonal(grid);
  
  int max_a = max1 > max2 ? max1 : max2;
  int max_b = max3 > max4 ? max3 : max4;

  int max = max_a > max_b ? max_a : max_b;

  std::cout << max;
  return 0;
}

int check_horizontal(int a[][dimensions]) {
  int max_product = 1;
  int product = 1;
  for (int i = 0; i < dimensions; ++i) {
    for (int j = 0; j <= dimensions - adjacent; ++j) {
      product = a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3];
      if (product > max_product) {
	max_product = product;
      }
    }
  }
  return max_product;
}

int check_vertical(int a[][dimensions]) {
  int max_product = 1;
  int product = 1;
  for (int i = 0; i <= dimensions - adjacent; ++i) {
    for (int j = 0; j < dimensions; ++j) {
      product = a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j];
      if (product > max_product) {
	max_product = product;
      }
    }
  }
  return max_product;  
}

int check_left_right_diagonal(int a[][dimensions]) {
  int max_product = 1;
  int product = 1;
  for (int i = 0; i <= dimensions - adjacent; ++i) {
    for (int j = 0; j <= dimensions - adjacent; ++j) {
      product = a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3];
      if (product > max_product) {
	max_product = product;
      }
    }
  }
  return max_product;    
}

int check_right_left_diagonal(int a[][dimensions]) {
  int max_product = 1;
  int product = 1;
  for (int i = adjacent - 1; i < dimensions; ++i) {
    for (int j = 0; j <= dimensions - adjacent; ++j) {
      product = a[i][j] * a[i - 1][j + 1] * a[i - 2][j + 2] * a[i - 3][j + 3];
      if (product > max_product) {
	max_product = product;
      }
    }
  }
  return max_product;    
}
