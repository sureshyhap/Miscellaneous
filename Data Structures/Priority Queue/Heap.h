#ifndef HEAP_H
#define HEAP_H

#include "BinaryTree.h"

template <typename T>
class Heap : public BinaryTree<T> {
 public:
  Heap();
  Heap(const Heap& h);
  ~Heap();
  Heap& operator=(const Heap& h);
  virtual bool insert(const T& element, const T& parent_element = T(), bool is_left = true);
  virtual bool remove(const T& element = T());
 protected:
  void percolate_up();
  void percolate_down();
 private:
};

#include "Heap.cpp"

#endif // HEAP_H

