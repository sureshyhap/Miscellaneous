#include <iostream>
#include "Priority_Queue.h"

int main(int argc, char* argv[]) {
  /*
  Heap<int> h;
  h.insert(88);
  h.insert(66);
  h.insert(77);
  h.insert(33);
  h.insert(51);
  h.insert(55);
  h.insert(75);
  h.insert(30);
  h.insert(22);
  h.insert(44);
  
  h.insert(75);
  h.remove();
  h.print_level_order();
  */

  Priority_Queue<int> h;
  h.push(88);
  h.push(66);
  h.push(77);
  h.push(33);
  h.push(51);
  h.push(55);
  h.push(75);
  h.push(30);
  h.push(22);
  h.push(44);
  
  h.push(75);
  h.pop();
  h.print_level();

  return 0;
}
