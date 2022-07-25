#include "Queue.h"
#include <iostream>

int main(int argc, char* argv[]) {
  Queue<int> q;
  q.push(2);
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.push(3);
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.push(4);
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.pop();
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.pop();
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.push(5);
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.push(10);
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.push(11);
  std::cout << q.front_() << " " << q.back_() << std::endl;
  q.push(12);
  std::cout << q.front_() << " " << q.back_() << std::endl;
  return 0;
}
