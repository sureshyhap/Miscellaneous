#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void counting_sort(std::vector<int>& v, int max_value) {
  std::vector<int> nums(max_value + 1);
  for (auto elem : v) {
    ++nums[elem];
  }
  int i = 0;
  for (int bucket = 0; bucket <= max_value; ++bucket) {
    for (int count = 0; count < nums[bucket]; ++count) {
      v[i++] = bucket;
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> v;
  for (int i = 0; i < 25; ++i) {
    unsigned int seed = i + time(NULL);
    srand(seed);
    v.push_back((rand() / 100) % 20);
  }
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  counting_sort(v, 19);
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  return 0;
}
