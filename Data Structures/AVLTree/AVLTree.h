#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinaryTree.h"

// Duplicate keys are not allowed
template <typename T>
class AVLTree : public BinaryTree<T> {
 public:
  AVLTree();
  AVLTree(const AVLTree& bt);
  ~AVLTree();
  AVLTree& operator=(const AVLTree& at);
  // Logarithmic search
  typename BinaryTree<T>::Node* search(const T& element);
  // Not allowing duplicates so if fails, is because there is already a Node
  // with data == element. Logarithmic insert
  bool insert(const T& element, const T& parent_element = T(), bool is_left = true);
  // Fails if no match found. Logarithmic delete
  bool remove(const T& element = T());
  // Logarithmic find the minimum element
  typename BinaryTree<T>::Node* find_min(typename BinaryTree<T>::Node* subtree_root = nullptr);
  // Logarithmic find the maximum element
  typename BinaryTree<T>::Node* find_max(typename BinaryTree<T>::Node* subtree_root = nullptr);
  typename BinaryTree<T>::Node* get_successor(typename BinaryTree<T>::Node* n);
  typename BinaryTree<T>::Node* get_predecessor(typename BinaryTree<T>::Node* n);
  const T& get_node(typename BinaryTree<T>::Node* n);
  typename BinaryTree<T>::Node* get_root();
  void print_pre_order();
  void print_post_order();
  void print_in_order();
 protected:
  typename BinaryTree<T>::Node* inorder_traversal_for_succ(typename BinaryTree<T>::Node* subtree_root, const T& element);
  typename BinaryTree<T>::Node* rev_inorder_traversal_for_pred(typename BinaryTree<T>::Node* subtree_root, const T& element);
  // Preorder traversal that copies the tree
  void preorder_for_copying(typename BinaryTree<T>::Node* subtree_root, typename BinaryTree<T>::Node*& parent_);
  // Postorder traversal that deletes the tree
  void postorder_for_deleting(typename BinaryTree<T>::Node* r);
  // Rebalances tree after imbalance
  void balance_tree(int imb_case, typename BinaryTree<T>::Node*& subtree_root);
  void left_rotation(typename BinaryTree<T>::Node*& subtree_root);
  void right_rotation(typename BinaryTree<T>::Node*& subtree_root);
  void left_right_double_rotation(typename BinaryTree<T>::Node*& subtree_root);
  void right_left_double_rotation(typename BinaryTree<T>::Node*& subtree_root);
  typename BinaryTree<T>::Node* root;
};

#include "AVLTree.cpp"

#endif // AVLTREE_H
