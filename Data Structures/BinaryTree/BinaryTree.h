#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>

template <typename T>
class BinaryTree {
 public:
  // Default constructor
  BinaryTree();
  // Copy constructor
  BinaryTree(const BinaryTree& bt);
  // Destructor
  virtual ~BinaryTree();
  // Assignment operator
  BinaryTree& operator=(const BinaryTree& bt);
  // Access a node with a given level and position in that lavel
  virtual T& access(int level, int position);
  // Search for an element in the tree
  virtual Node* search(const T& element);
  // Insert element as a child of parent_element
  // bool because can fail if parent element has 2 children already
  // or parent element is not in the tree
  virtual bool insert(const T& element, const T& parent_element = T(), bool is_left = true);
  // Remove element from the tree
  virtual void remove(const T& element = T());
 protected:
  struct Node {
    // Default constructor
    Node(const T& data, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr);
    T data;
    Node* parent;
    Node* left_child, * right_child;
  };
  // Returns index of found element in tree vector or -1 if not found
  int search_index(const T& element);
  // Nodes of the tree stored in level order traversal order
  std::vector<Node*> tree;
  int depth;
};

#include "BinaryTree.cpp"

// BINARYTREE_H
#endif
