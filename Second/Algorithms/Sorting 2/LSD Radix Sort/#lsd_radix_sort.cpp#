////////////// Think about signed and unsigned ints ///////////////////

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <cmath>

const int SORT_BY_LAST = 10;
const int MAX_NUM = 999;
const int RUNS = ceil(log(MAX_NUM) / log(SORT_BY_LAST));

void lsd_radix_sort(std::vector<int>& v) {
  std::vector<std::list<int>> last_digits(SORT_BY_LAST);
  int size = v.size();
  int last_dig = {};
  for (int runs = 0; runs < RUNS; ++runs) {
    for (int i = 0; i < size; ++i) {
      last_dig = static_cast<int>(v[i] / pow(SORT_BY_LAST, runs)) % SORT_BY_LAST;
      last_digits[last_dig].push_back(v[i]);
    }
    int k = 0;
    for (int i = 0; i < SORT_BY_LAST; ++i) {
      for (std::list<int>::const_iterator cit = last_digits[i].cbegin();
	   cit != last_digits[i].cend(); ++cit) {
	v[k++] = *cit;
      }
      last_digits[i].clear();
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> v;
  for (int i = 0; i < 25; ++i) {
    unsigned int seed = i + time(NULL);
    srand(seed);
    v.push_back((rand() / 100) % 1000);
  }
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  lsd_radix_sort(v);
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << '\n';
  return 0;
}
