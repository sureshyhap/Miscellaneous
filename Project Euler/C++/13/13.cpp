#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

const int number_of_numbers = 100;
const int digits = 50;

int main(int argc, char* argv[]) {
  std::ifstream infile("number.txt");
  std::vector<std::string> v;
  std::string number;
  for (int i = 0; i < number_of_numbers; ++i) {
    std::getline(infile, number);
    v.push_back(number);
  }
  const int max_digit_length = 10;
  const int num_vecs_per_number = digits / max_digit_length;
  std::vector<std::vector<long long int>> split_digits;
  for (int i = 0; i < number_of_numbers; ++i) {
    std::vector<long long int> part;
    for (int j = 0; j < num_vecs_per_number; ++j) {
      std::string part_num_str = v[i].substr(j * 10, 10);
      std::istringstream iss(part_num_str);
      long long int part_num_int = 0;
      iss >> part_num_int;
      part.push_back(part_num_int);
    }
    split_digits.push_back(part);
  }
  long long int sum[num_vecs_per_number] = {0};
  for (int i = 0; i < number_of_numbers; ++i) {
    for (int j = num_vecs_per_number - 1; j >= 0; --j) {
      sum[j] += split_digits[i][j];
    }
  }
  for (int j = num_vecs_per_number - 1; j > 0; --j) {
    int carry = sum[j] / 1e10; // Should not use magic number 10, but max_digit_length instead
    sum[j - 1] += carry;
  }
  std::cout << sum[0];
  return 0;
}
