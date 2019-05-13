#include "BinaryTree.h"

int main(int argc, char* argv[]) {
  BinaryTree<char> b;
  BinaryTree<char>::Node* five;
  /*
  std::cout << b.remove('5') << '\n';
  */
  b.insert('5');
  /*
  std::cout << b.access(0, 0) << '\n';
  five = b.search('5');
  std::cout << five->data << '\n';
  */
  b.remove('5');
  /*
  five = b.search('5');
  if (!five) {
    std::cout << "No fives in tree" << '\n';
  }
  */
  b.insert('A');
  b.insert('C', 'A', false);
  b.insert('B', 'A');
  b.insert('E', 'B', false);
  b.insert('D', 'B');
  b.insert('F', 'C');
  b.insert('M', 'F', false);
  b.insert('H', 'D');
  b.insert('I', 'D', false);
  b.insert('J', 'E');
  b.print_level_order();
  std::cout << '\n';
  //std::cout << b.access(3, 2);
  five = b.search('D');
  //  std::cout << five->data;
  b.print_pre_order();
  std::cout << '\n';
  b.print_post_order();
  std::cout << '\n';
  b.print_in_order();
  std::cout << '\n';  
  return 0;
}
