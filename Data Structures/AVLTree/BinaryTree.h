#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>

template <typename T>
class BinaryTree {
 public:
  struct Node;
  // Default constructor
  BinaryTree();
  // Copy constructor
  BinaryTree(const BinaryTree& bt);
  // Destructor
  virtual ~BinaryTree();
  // Assignment operator
  BinaryTree& operator=(const BinaryTree& bt);
  // Access a node with a given level and position in that level
  virtual T& access(int level, int position);
  // Search for an element in the tree
  virtual Node* search(const T& element);
  // Insert element as a child of parent_element
  // bool because can fail if parent element has 2 children already
  // or parent element is not in the tree
  virtual bool insert(const T& element, const T& parent_element = T(), bool is_left = true);
  // Remove element from the tree
  virtual bool remove(const T& element = T());
  void print_level_order();
  // Assumes there is at least a root /////////////////////////
  virtual void print_pre_order();
  virtual void print_post_order();
  virtual void print_in_order();
  struct Node {
    friend class BinaryTree<T>;
    // Default constructor
    Node(const T& data, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr, int d_l = -1, int d_r = -1);
    T data;
    Node* parent;
    Node* left_child, * right_child;
    int depth_left, depth_right;
  };
 protected:
  // Returns index of found element in tree vector or -1 if not found
  int search_index(const T& element);
  void preorder(Node* subtree_root);
  void postorder(Node* subtree_root);
  void inorder(Node* subtree_root);
  // Nodes of the tree stored in level order traversal order
  std::vector<Node*> tree;
  // Depth of root
  int depth;
};
#include "BinaryTree.cpp"

// BINARYTREE_H
#endif
