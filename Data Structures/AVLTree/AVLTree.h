#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinaryTree.h"

template <typename T>
class AVLTree : public BinaryTree {
 public:
  AVLTree();
  AVLTree(const AVLTree& bt);
  ~AVLTree();
  AVLTree& operator=(const AVLTree& at);
  // Logarithmic search
  Node* search(const T& element);
  // Not allowing duplicates so if fails, is because there is already a Node
  // with data == element. Logarithmic insert
  bool insert(const T& element, const T& parent_element = T(), bool is_left = true);
  // Fails if no match found. Logarithmic delete
  bool remove(const T& element = T());
  // Logarithmic find the minimum element
  Node* find_min(Node* subtree_root = nullptr);
  // Logarithmic find the maximum element
  Node* find_max(Node* subtree_root = nullptr);
  Node* get_successor(Node* n);
  Node* get_predecessor(Node* n);
 protected:
  // Preorder traversal that copies the tree
  void preorder_for_copying(Node* subtree_root, Node*& parent_);
  // Postorder traversal that deletes the tree
  void postorder_for_deleting(Node* r);
  // Rebalances tree after imbalance
  void balance_tree(int imb_case, Node*& subtree_root);
  void left_rotation(Node*& subtree_root);
  void right_rotation(Node*& subtree_root);
  void left_right_double_rotation(Node*& subtree_root);
  void right_left_double_rotation(Node*& subtree_root);
  Node* root;
};

#include "AVLTree.cpp"

#endif // AVLTREE_H
