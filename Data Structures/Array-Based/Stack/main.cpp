#include <iostream>
#include "Stack.h"

int main(int argc, char* argv[]) {
  Stack<int> s;
  s.push(5);
  std::cout << s.top() << '\n';
  s.push(4);
  std::cout << s.top() << '\n';
  s.push(1);
  std::cout << s.top() << '\n';
  s.pop();
  std::cout << s.top() << '\n';
  s.push(10);
  s.push(15);
  std::cout << s.top() << '\n';
  
  return 0;
}
