template <typename T>
AVLTree<T>::AVLTree() : BinaryTree() {
  root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree& at) {
  depth = at.depth;
  // Establishes the root
  root = new Node(at.root->data, nullptr, nullptr, nullptr, at.root->d_l, at.root->d_r);
  // Creates new identicaltree with root as the root
  preorder_for_copying(at.root, root);
}

template <typename T>
AVLTree<T>::~AVLTree() {
  // Deletes all nodes of the tree
  postorder_for_deleting(root);
  ~BinaryTree();
}


template <typename T>
typename AVLTree::AVLTree& AVLTree<T>::operator=(const AVLTree& at) {
  depth = at.depth;
  // Deletes old self
  postorder_for_deleting(root);
  root = new Node(at.root->data, nullptr, nullptr, nullptr, at.root->d_l, at.root->d_r);
  // Becomes new tree
  preorder_for_copying(at.root, root);  
}


template <typename T>
AVLTree<T>::Node* AVLTree<T>::search(const T& element) {
  if (root == nullptr) {
    return nullptr;
  }
  // Start at the root
  Node* temp = root;
  // While not found, check left and right children
  while (temp->data != element) {
    if (element < temp->data) {
      temp = temp->left_child;
    }
    else if (element > temp->data) {
      temp = temp->right_child;
    }
    // Not found
    if (!temp) {
      return nullptr;
    }
  }
  // Found
  return temp;
}

template <typename T>
void AVLTree<T>::insert(const T& element, const T& parent_element, bool is_left) {
  // Initial insert
  if (root == nullptr) {
    root = new Node(element);
    ++depth;
    return;
  }
  // Find correct spot for the new data
  Node* temp = root;
  bool elem_is_left = true;
  while (true) {
    if (element < temp->data) {
      if (temp->left_child != nullptr) {
	temp = temp->left_child;
      }
      else {
	break;
      }
    }
    if (element > temp->data) {
      if (temp->right_child != nullptr) {
	temp = temp->right_child;
      }
      else {
	elem_is_left = false;
	break;
      }
    }
    // Duplicate already in tree
    else {
      return false;
    }
  }
  // Create new node and attach it to the tree
  Node* new_node = new Node(element, temp);
  if (elem_is_left) {
    temp->left_child = new_node;
  }
  else {
    temp->right_child = new_node;
  }
  for (Node* temp2 = new_node; temp2 != nullptr; temp2 = temp2->parent) {
    Node*& par = temp2->parent;
    // temp2 is a left child
    if (temp2 == par->left_child) {
      ++(par->depth_left);
      // Imbalance from left child of par
      if ((par->depth_left - par->depth_right) > 1) {
	// Insertion was into left subtree of par's left child (temp)
	if (element < temp->data) {
	  // Case 1 rotation
	  balance_tree(1, par);
	  break;
	}
	else if (element > temp->data) {
	  // Case 2 rotation
	  balance_tree(2, par);
	  break;
	}
      }
    }
    // temp2 is a right child
    else if (temp2 == par->right_child) {
      ++(par->depth_right);
      // Imbalance from right child of par
      if ((par->depth_left - par->depth_right) < -1) {
	// Insertion was into left subtree of par's right child (temp)
	if (element < temp->data) {
	  // Case 3 rotation
	  balance_tree(3, par);
	  break;
	}
	else if (element > temp->data) {
	  // Case 4 rotation
	  balance_tree(4, par);
	  break;
	}
      }
    }
  }
}

template <typename T>
bool AVLTree<T>::remove(const T& element) {
  // Find the potential node to remove
  Node* node_to_rmv = search(element);
  if (node_to_rmv == nullptr) {
    return false;
  }
  // Is a leaf
  if (!node_to_rmv->left_child && !node_to_rmv->right_child) {
    // Is a left child
    if (node_to_rmv->parent->left_child == node_to_rmv) {
      node_to_rmv->parent->left_child = nullptr;
      delete node_to_rmv;
      return true;
    }
    // Is a right child
    else if (node_to_rmv->parent->right_child == node_to_rmv) {
      node_to_rmv->parent->right_child = nullptr;
      delete node_to_rmv;
      return true;
    }
  }
  // If node has only 1 child
  // Has a left child
  if (node_to_rmv->left_child != nullptr && node_to_rmv->right_child == nullptr) {
    // Is a left child
    if (node_to_rmv->parent->left_child == node_to_rmv) {
      node_to_rmv->parent->left_child = node_to_rmv->left_child;
      delete node_to_rmv;
      return true;
    }
    // Is a right child
    else if (node_to_rmv->parent->right_child == node_to_rmv) {
      node_to_rmv->parent->right_child = node_to_rmv->left_child;
      delete node_to_rmv;
      return true;
    }
  }
  // Has a right child
  else if (node_to_rmv->left_child == nullptr && node_to_rmv->right_child != nullptr) {
    // Is a left child
    if (node_to_rmv->parent->left_child == node_to_rmv) {
      node_to_rmv->parent->left_child = node_to_rmv->right_child;
      delete node_to_rmv;
      return true;
    }
    // Is a right child
    else if (node_to_rmv->parent->right_child == node_to_rmv) {
      node_to_rmv->parent->right_child = node_to_rmv->right_child;
      delete node_to_rmv;
      return true;
    }
  }

  // The node has 2 children
  Node* right_ch = node_to_rmv->right_child;
  // Minimum value in right subtree
  Node* least_in_right = find_min(right_ch);
  // Overwrite the data in node to remove
  node_to_rmv->data = least_in_right->data;
  // Bypassing old node with the data
  least_in_right->parent->left_child = least_in_right->right_child;

  // Need to update the depths and check for imbalances
  Node* temp = least_in_right;
  while (temp->parent != nullptr) {
    // temp is a left child
    if (temp->parent->left_child == temp) {
      // Decrement left depth because here it was on the left path that the node was deleted
      --(temp->parent->depth_left);
      // If became too right heavy, attempt a rebalance
      if (temp->parent->depth_left - temp->parent->depth_right < -1) {
	// It turns out this will distinguish between case 3 and 4
	if (temp->parent->right_child->depth_left > temp->parent->right_child->depth_right) {
	  // Case 3 rotation
	  balance_tree(3, temp->parent);
	  break;
	}
	else if (temp->parent->right_child->depth_left < temp->parent->right_child->depth_right) {
	  // Case 4 rotation
	  balance_tree(4, temp->parent);
	  break;
	}
      }

    }
    // temp is a right child
    else if (temp->parent->right_child == temp) {
      // Decrement right depth because here it was on the right path that the node was deleted
      --(temp->parent->depth_right);
      // If became too left heavy, attempt a rebalance
      if (temp->parent->depth_left - temp->parent->depth_right > 1) {
	// It turns out this will distinguish between case 1 and 2
	if (temp->parent->left_child->depth_left > temp->parent->left_child->depth_right) {
	  // Case 1 rotation
	  balance_tree(1, temp->parent);
	  break;
	}
	else if (temp->parent->left_child->depth_left < temp->parent->left_child->depth_right) {
	  // Case 2 rotation
	  balance_tree(2, temp->parent);
	  break;
	}	
      }
    }
    temp = temp->parent;
  }
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find_min(Node* subtree_root) {
  // If no argument, use root as subtree's root
  if (!subtree_root) {
    subtree_root = root;
  }
  Node* temp = subtree_root;
  // Keep marching left until found last node on this path
  while (temp->left_child != nullptr) {
    temp = temp->left_child;
  }
  return temp;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find_max(Node* subtree_root) {
  // If no argument, use root as subtree's root
  if (!subtree_root) {
    subtree_root = root;
  }
  Node* temp = subtree_root;
  // Keep marching right until found last node on this path
  while (temp->right_child != nullptr) {
    temp = temp->right_child;
  }
  return temp;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::get_successor(Node* n) {
  Node* in_subtree = nullptr, * not_in_subtree = nullptr;
  // Next element (value based) is the smallest value in the right subtree
  in_subtree = find_min(n->right_child);
  Node* temp = n->parent;
  while (temp->data < n->data) {
    temp = temp->parent;
  }
  while (temp->data > n->data) {
    temp = temp->parent;
  }
  not_in_subtree = temp->right_child;
  return in_subtree->data < not_in_subtree->data ? in_subtree : not_in_subtree;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::get_predecessor(Node* n) {
  Node* in_subtree = nullptr, * not_in_subtree = nullptr;
  // Previous element (value based) is the largest value in the left subtree
  in_subtree = find_max(n->left_child);
  // For root, previous element must be in the subtree because the subtree is the whole tree
  if (n == root) {
    return in_subtree;
  }
  Node* temp = n->parent;
  while (temp->data > n->data) {
    temp = temp->parent;
  }
  while (temp->data < n->data) {
    temp = temp->parent;
  }
  not_in_subtree = temp->left_child;
  return in_subtree->data > not_in_subtree->data ? in_subtree : not_in_subtree;
}


template <typename T>
void AVLTree<T>::preorder_for_copying(Node* subtree_root, Node*& parent_) {
  if (subtree_root == nullptr) {
    return;
  }
  const Node*& left = subtree_root->left_child;
  const Node*& right = subtree_root->right_child;
  if (left != nullptr) {
    Node* new_node = new Node(left->data, parent_, nullptr, nullptr, left->depth_left, left->depth_right);
    parent_->left_child = new_node;
    preorder_for_copying(left, new_node);
  }
  if (right != nullptr) {
    Node* new_node = new Node(right->data, parent_, nullptr, nullptr, right->depth_left, right->depth_right);
    parent_->right_child = new_node;
    preorder_for_copying(right, new_node);
  }
}

template <typename T>
void AVLTree<T>::postorder_for_deleting(Node* r) {
  if (r == nullptr) {
    return;
  }
  post_order_for_deleting(r->left_child);
  post_order_for_deleting(r->right_child);
  delete r;
}

template <typename T>
void AVLTree<T>::balance_tree(int imb_case, Node*& subtree_root) {
  switch (imb_case) {
  case 1:
    right_rotation(subtree_root);
    break;
  case 2:
    left_right_double_rotation(subtree_root);
    break;
  case 3:
    right_left_double_rotation(subtree_root);
    break;
  case 4:
    left_rotation(subtree_root);
    break;
  }
}

template <typename T>
void AVLTree<T>::left_rotation(Node*& subtree_root) {
  Node* right_child_of_left_child = subtree_root->left_child->right_child;
  Node* subtree_roots_parent = subtree_root->parent;
  subtree_root->left_child->right_child = subtree_root;
  subtree_root->left_child->parent = subtree_roots_parent;
  subtree_root->parent = subtree_root->left_child;
  subtree_root = subtree_root->left_child;
  subtree_root->right_child->left_child = right_child_of_left_child;
  subtree_root->right_child->left_child->parent = subtree_root->right_child;
  ++(subtree_root->d_r);
  subtree_root->right_child->d_l -= 2;
}

template <typename T>
void AVLTree<T>::right_rotation(Node*& subtree_root) {
  Node* left_child_of_right_child = subtree_root->right_child->left_child;
  Node* subtree_roots_parent = subtree_root->parent;
  subtree_root->right_child->left_child = subtree_root;
  subtree_root->right_child->parent = subtree_roots_parent;
  subtree_root->parent = subtree_root->right_child;
  subtree_root = subtree_root->right_child;
  subtree_root->left_child->right_child = left_child_of_right_child;
  subtree_root->left_child->right_child->parent = subtree_root->left_child;
  ++(subtree_root->d_l);
  subtree_root->left_child->d_r -= 2;
}

template <typename T>
void AVLTree<T>::left_right_rotation(Node*& subtree_root) {
  left_rotation(subtree_root->left_child);
  right_rotation(subtree_root);
}

template <typename T>
void AVLTree<T>::right_left_rotation(Node*& subtree_root) {
  right_rotation(subtree_root->right_child);
  left_rotation(subtree_root);
}
