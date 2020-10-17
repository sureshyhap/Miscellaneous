#include "AVLTree.h"

int main(int argc, char* argv[]) {
  AVLTree<int> avl1;
  avl1.insert(30);
  avl1.print_pre_order();
  std::cout << std::endl;
  avl1.insert(17);
  avl1.print_pre_order();
  std::cout << std::endl;
  avl1.insert(5);
  avl1.print_pre_order();
  std::cout << std::endl;


  avl1.insert(75);

  avl1.print_pre_order();
  std::cout << std::endl;

  avl1.insert(13);
  avl1.print_pre_order();
  std::cout << std::endl;
  
  avl1.insert(42);
  avl1.print_pre_order();
  std::cout << std::endl;
  avl1.insert(49);
  avl1.print_pre_order();
  std::cout << std::endl;

  avl1.insert(33);
  avl1.print_pre_order();
  std::cout << std::endl;

  
  avl1.insert(86);
  avl1.print_pre_order();
  std::cout << std::endl;
  
  avl1.insert(80);
  avl1.print_pre_order();
  std::cout << std::endl;
  
  //  std::cout << avl1.get_predecessor(avl1.search(86))->data << std::endl;
  ////////////////////// Make succ and pred work for the largest and smallest values respectively
  
  avl1.remove(80);
  avl1.print_pre_order();
  std::cout << std::endl;


  avl1.remove(30);
  avl1.print_pre_order();
  std::cout << std::endl;

  
  avl1.remove(75);
  avl1.print_pre_order();
  std::cout << std::endl;

  avl1.remove(49);
  avl1.print_pre_order();
  std::cout << std::endl;
  
  avl1.remove(5);
  avl1.print_pre_order();
  std::cout << std::endl;
  
  
  avl1.remove(13);
  avl1.print_pre_order();
  std::cout << std::endl;

  avl1.remove(42);
  avl1.print_pre_order();
  std::cout << std::endl;

  avl1.remove(33);
  avl1.print_pre_order();
  std::cout << std::endl;

  avl1.remove(17);
  avl1.print_pre_order();
  std::cout << std::endl;

  avl1.remove(86);
  avl1.print_pre_order();
  std::cout << std::endl;

  
  /*
  std::cout << avl1.search(42)->depth_left << " " << avl1.search(42)->depth_right << std::endl;
  std::cout << avl1.search(17)->depth_left << " " << avl1.search(17)->depth_right << std::endl;
  std::cout << avl1.search(75)->depth_left << " " << avl1.search(75)->depth_right << std::endl;
  std::cout << avl1.search(5)->depth_left << " " << avl1.search(5)->depth_right << std::endl;
  //  std::cout << avl1.search(30)->depth_left << " " << avl1.search(30)->depth_right << std::endl;
  std::cout << avl1.search(49)->depth_left << " " << avl1.search(49)->depth_right << std::endl;
  std::cout << avl1.search(86)->depth_left << " " << avl1.search(86)->depth_right << std::endl;
  std::cout << avl1.search(13)->depth_left << " " << avl1.search(13)->depth_right << std::endl;
  std::cout << avl1.search(33)->depth_left << " " << avl1.search(33)->depth_right << std::endl;
  //  std::cout << avl1.search(80)->depth_left << " " << avl1.search(80)->depth_right << std::endl;
  */
  

  
  //std::cout << avl1.find_max(avl1.get_root()->left_child)->data << std::endl;
  
  return 0;
}
