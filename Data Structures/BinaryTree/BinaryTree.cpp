#include <cmath>

template <typename T>
BinaryTree<T>::BinaryTree() : depth(-1) {
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& bt) {
  const int size = bt.tree.size();
  for (int i = 0; i < size; ++i) {
    Node* p = new Node(*(bt.tree[i]));
    tree.push_back(p);
  }
  depth = bt.depth;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
}

template <typename T>
typename BinaryTree<T>::BinaryTree& BinaryTree<T>::operator=(const BinaryTree& bt) {
  tree.clear();
  const int size = bt.tree.size();
  for (int i = 0; i < size; ++i) {
    Node* p = new Node(*(bt.tree[i]));
    tree.push_back(p);
  }
  depth = bt.depth;
}

template <typename T>
T& BinaryTree<T>::access(int level, int position) {
  try {
    int index = pow(2, level) - 1 + position;
    if (index >= tree.size() || tree[index] == nullptr) {
      throw "Not a valid position in tree. Either out of range or the node position is empty.
Returning root's data because must return something. Disregard return value.";
    }
    return tree[index]->data;
  }
  catch (const char* msg) {
    std::cerr << msg << std::endl;
  }
  ///////////////////////////////////////////////////////////////////////////////////
  // Fix the return value for this case.     //
  // If the tree is empty, there is no root! //
  ///////////////////////////////////////////////////////////////////////////////////
  
  return tree[0]->data;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::search(const T& element) {
  int index = search_index(element);
  return index == -1 ? nullptr : tree[index];
}

template <typename T>
bool BinaryTree<T>::insert(const T& element, const T& parent_element, bool is_left) {
  if (tree.empty()) {
    Node* new_elem = new Node(element);
    tree.push_back(new_elem);
    ++depth;
    return true;
  }
  int index = search_index(parent_element);
  Node* par = index == -1 ? nullptr : tree[index];
  // Parent element is not in the tree
  if (par == nullptr) {
    return false;
  }
  // Parent element already has 2 children
  if (par->left_child != nullptr && par->right_child != nullptr) {
    return false;
  }
  Node* new_elem = new Node(element, par);
  if (is_left) {
    par->left_child = new_elem;
  }
  else {
    par->right_child = new_elem;
  }
  int size = tree.size();
  // If the index of the parent corresponds to the deapest level
  if (index > pow(2, depth - 1) && index < size) {
    tree.resize(pow(2, ++depth), nullptr);
  }
  if (is_left) {
    // Element at 2 * index + 1 is left child of parent at index
    tree[2 * index + 1] = new_elem;
  }
  else {
    // Element at 2 * index + 2 is right child of parent at index
    tree[2 * index + 2] = new_elem;
  }
  return true;
}

template <typename T>
void BinaryTree<T>::remove(const T& element) {
  int index = search_index(element);
  Node* elem = index == -1 ? nullptr : tree[index];
  // Parent element is not in the tree
  if (elem == nullptr) {
    return false;
  }
  while (elem->left_child != nullptr || elem->right_child != nullptr) {
    if (elem->right_child == nullptr) {
      // If elem is its parent's left child
      if (elem == elem->parent->left_child) {
	
	/////////////////////////// Move up the data ////////////////////
      }
    }
    else if (elem->right_child == nullptr)
    /*
    if (elem->right_child == nullptr) {
      // If elem is not a child of root
      if (elem->parent != nullptr) {
	elem->parent
      }
      }
    T min = T();
    // elem has 2 children
    if (elem->left_child != nullptr && elem->right_child != nullptr) {
      min = elem->left_child < elem->right_child ? elem->left_child : elem->right_child;
      }*/
    
  }
  delete elem;
  elem = nullptr;
  bool all_nulls_at_depth = true;
  int size = tree.size();
  for (int check_all_nulls_at_depth = pow(2, depth - 1) + 1; check_all_nulls_at_depth < size; ++check_all_nulls_at_depth) {
    if (tree[check_a;;_nulls_at_depth] != nullptr) {
      all_nulls_at_depth = false;
      break;
    }
  }
  if (all_null_at_depth == true) {
    tree.resize(pow(2, depth--) - 1);
  }
}

template <typename T>
int BinaryTree<T>::search_index(const T& element) {
  const int size = tree.size();
  for (int i = 0; i < size; ++i) {
    if (tree[i] == nullptr) {
      continue;
    }
    if (tree[i]->data == element) {
      return i;
    }
  }
  // If not found, return -1
  return -1;
}
