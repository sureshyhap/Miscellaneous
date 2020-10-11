#include <iostream>
#include <cstring>

void replace(char*& cs, int start, int len, const char* to_splice);

int main(int argc, char* argv[]) {
  char* cs = new char[6 + 1];
  strcpy(cs, "Hello World!");
  std::cout << cs << std::endl;
  replace(cs, 6, 5, "Planet");
  std::cout << cs << std::endl;
  replace(cs, 6, 6, "Hi");
  std::cout << cs << std::endl;
  replace(cs, 6, 2, "By");
  std::cout << cs << std::endl;
  return 0;
}

void replace(char*& cs, int start, int len, const char* to_splice) {
  int len_to_splice = strlen(to_splice);
  int len_original = strlen(cs);
  int diff = len_to_splice - len;
  if (len_to_splice != len) {
    char* temp = new char[len_original + diff + 1];
    for (int i = 0; i < start; ++i) {
      temp[i] = cs[i];
    }
    for (int i = 0; i < len_to_splice; ++i) {
      temp[start + i] = to_splice[i];
    }
    for (int i = start + len; i < len_original; ++i) {
      temp[i + diff] = cs[i];
    }
    int len_temp = len_original + diff;
    temp[len_temp] = '\0';
    delete cs;
    cs = new char[len_temp + 1];
    strcpy(cs, temp);
    delete temp;
  }
  else {
    for (int i = 0; i < len_to_splice; ++i) {
      cs[start + 1] = to_splice[i];
    }
  }
}
