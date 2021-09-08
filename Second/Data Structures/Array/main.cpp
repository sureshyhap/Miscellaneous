#include <iostream>
#include "Array.h"

int main(int argc, char* argv[]) {
  int a[] = {4, 7, 13, 4, 13, 21, 24};
  int b[] = {1, 13, 6, 24, 13, 7, 8};
  Array<int> arr1(a, 7), arr2(b, 7);
  std::cout << std::boolalpha;
  List<int>* p_arr3 = arr1.difference_list(arr2);
  p_arr3->print();
  /*
  List<int>* p_arr3 = new Array<int>(*(arr1.union_list(arr2)));
  p_arr3->print();
  */
  /*
  Array<int> arr3(*(arr1.to_set()));
  arr3.print();
  */
  /*
  arr1.merge_sorted(arr2);
  arr1.print();
  */
  /*
  arr2.insert_into_sorted(2);
  arr2.print();
  */
  /*
  std::cout << arr1.get_min() << '\n';
  std::cout << arr2.get_min() << '\n';
  std::cout << arr1.get_sum() << '\n';
  std::cout << arr1.get_avg() << '\n';
  */
  /*
  std::cout << arr1.check_is_sorted() << '\n';
  std::cout << arr2.check_is_sorted() << '\n';
  std::cout << arr1.find_element(4) << '\n';
  std::cout << arr2.find_element(4) << '\n';
  */
  /*
  Array<int> a;
  std::cout << a.get_present_index() << std::endl;
  a.insert_beg(5);
  a.insert_end(4);
  a.insert_beg(1);
  a.print();
  Array<int> b(a);
  b.print();
  Array<int> c;
  c = {b};
  c.print();
  a.insert(1, 10);
  a.print();
  a.set(1, 11);
  a.print();
  std::cout << a.find_kth(1) << std::endl;
  std::cout << a.find_element(11) << std::endl;
  std::cout << a.get_present_index() << std::endl;
  a.insert_end(14);
  std::cout << a.get_present_index() << std::endl;
  a.move_prev();
  std::cout << a.get_present_index() << std::endl;
  a.print();
  a.remove(3);
  a.print();
  std::cout << a.get_present_index() << std::endl;
  //  a.remove_beg();
  a.print();
  std::cout << a.get_present_index() << std::endl;
  //  a.remove_end();
  a.print();
  std::cout << a.get_present_index() << std::endl;
  a.remove_element(5);
  a.print();
  return 0;
  */
}
