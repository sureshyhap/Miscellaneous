#include <iostream>
#include <cstring>

void replace(char*& cs, int start, int len, const char* to_splice);

int main(int argc, char* argv[]) {
  char* cs = new char[12 + 1];
  strcpy(cs, "Hello World!abcedef");
  std::cout << cs << std::endl;
  replace(cs, 6, 5, "Planet");
  std::cout << cs << std::endl;
  replace(cs, 6, 6, "Hi");
  std::cout << cs << std::endl;
  replace(cs, 6, 2, "By");
  std::cout << cs << std::endl;
  delete [] cs;
  return 0;
}

void replace(char*& cs, int start, int len, const char* to_splice) {
  int len_to_splice = strlen(to_splice);
  int len_original = strlen(cs);
  if (start + len > len_original) {
    return;
  }
  int diff = len_to_splice - len;
  int len_temp = len_original + diff;
  char* temp = new char[len_temp + 1];
  if (diff < 0) {
    for (int i = 0; i < start; ++i) {
      temp[i] = cs[i];
    }
    for (int i = 0; i < len_to_splice; ++i) {
      temp[start + i] = to_splice[i];
    }
    for (int i = start; i < len_temp; ++i) {
      temp[i + len_to_splice] = cs[i + len];
    }
    temp[len_temp] = '\0';
    delete [] cs;
    cs = new char[len_temp + 1];
    strcpy(cs, temp);
    delete [] temp;
    return;
  }
  else if (len_to_splice != len) {
    for (int i = 0; i < start; ++i) {
      temp[i] = cs[i];
    }
    for (int i = 0; i < len_to_splice; ++i) {
      temp[start + i] = to_splice[i];
    }
    for (int i = start + len; i < len_original; ++i) {
      temp[i + diff] = cs[i];
    }
    temp[len_temp] = '\0';
    delete [] cs;
    cs = new char[len_temp + 1];
    strcpy(cs, temp);
    delete [] temp;
  }
  else {
    for (int i = 0; i < len_to_splice; ++i) {
      cs[start + i] = to_splice[i];
    }
  }
}
