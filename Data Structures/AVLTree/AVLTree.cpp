template <typename T>
AVLTree<T>::AVLTree() : BinaryTree<T>() {
  root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree& at) {
  this->depth = at.depth;
  // Establishes the root
  root = new typename BinaryTree<T>::Node(at.root->data, nullptr, nullptr, nullptr, at.root->d_l, at.root->d_r);
  // Creates new identicaltree with root as the root
  preorder_for_copying(at.root, root);
}

template <typename T>
AVLTree<T>::~AVLTree() {
  // Deletes all nodes of the tree
  postorder_for_deleting(root);
  //  ~BinaryTree<T>;
}


template <typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree& at) {
  this->depth = at.depth;
  // Deletes old self
  postorder_for_deleting(root);
  root = new typename BinaryTree<T>::Node(at.root->data, nullptr, nullptr, nullptr, at.root->d_l, at.root->d_r);
  // Becomes new tree
  preorder_for_copying(at.root, root);  
}


template <typename T>
typename BinaryTree<T>::Node* AVLTree<T>::search(const T& element) {
  if (root == nullptr) {
    return nullptr;
  }
  // Start at the root
  typename BinaryTree<T>::Node* temp = root;
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
bool AVLTree<T>::insert(const T& element, const T& parent_element, bool is_left) {
  // Initial insert
  if (root == nullptr) {
    root = new typename BinaryTree<T>::Node(element);
    //    ++(this->depth);
    return true;
  }
  // Find correct spot for the new data
  typename BinaryTree<T>::Node* temp = root;
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
    else if (element > temp->data) {
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
  typename BinaryTree<T>::Node* new_node = new typename BinaryTree<T>::Node(element, temp);
  if (elem_is_left) {
    temp->left_child = new_node;
  }
  else {
    temp->right_child = new_node;
  }
  for (typename BinaryTree<T>::Node* temp2 = new_node; temp2->parent != nullptr; temp2 = temp2->parent) {
    typename BinaryTree<T>::Node* par = temp2->parent;
    // temp2 is a left child
    if (temp2 == par->left_child) {
      // The left depth should be increased
      if (temp2->depth_right != temp2->depth_left || temp2->depth_right == -1) {
	++(par->depth_left);
      }
      // Imbalance from left child of par
      if ((par->depth_left - par->depth_right) > 1) {
	// Insertion was into left subtree of par's left child (temp)
	if (element < temp2->data) {
	  // Case 1 rotation
	  if (par->parent != nullptr) {
	    if (par->parent->left_child == par) {
	      balance_tree(1, par->parent->left_child);
	      return true;
	    }
	    else {

	      balance_tree(1, par->parent->right_child);
	      return true;
	    }
	  }
	  else {
	    balance_tree(1, root);
	    return true;
	  }
	}
	else if (element > temp2->data) {
	  // Case 2 rotation
	  if (par->parent != nullptr) {
	    if (par->parent->left_child == par) {
	      balance_tree(2, par->parent->left_child);
	      return true;
	    }
	    else {
	      balance_tree(2, par->parent->right_child);
	      return true;
	    }
	  }
	  else {
	    balance_tree(2, root);
	    return true;
	  }
	}
      }
    }
    // temp2 is a right child
    else if (temp2 == par->right_child) {
      // The right depth should be increased
      if (temp2->depth_right != temp2->depth_left || temp2->depth_right == -1) {
	++(par->depth_right);
      }
      // Imbalance from right child of par
      if ((par->depth_left - par->depth_right) < -1) {

	// Insertion was into left subtree of par's right child (temp)
	if (element < temp2->data) {
	  // Case 3 rotation
	  if (par->parent != nullptr) {
	    if (par->parent->left_child == par) {
	      balance_tree(3, par->parent->left_child);
	      return true;
	    }
	    else {
	      balance_tree(3, par->parent->right_child);
	      return true;
	    }
	  }
	  else {
	    balance_tree(3, root);
	    return true;
	  }
	}
	else if (element > temp2->data) {
	  // Case 4 rotation
	  if (par->parent != nullptr) {
	    if (par->parent->left_child == par) {
	      balance_tree(4, par->parent->left_child);
	      return true;
	    }
	    else {
	      balance_tree(4, par->parent->right_child);
	      return true;
	    }
	  }
	  else {
	    balance_tree(4, root);
	    return true;
	  }
	}
      }
    }
  }
}

template <typename T>
bool AVLTree<T>::remove(const T& element) {
  typename BinaryTree<T>::Node* temp = nullptr;
  typename BinaryTree<T>::Node* least_in_right = nullptr;
  typename BinaryTree<T>::Node*& to_delete = least_in_right;
  // Find the potential node to remove
  typename BinaryTree<T>::Node* node_to_rmv = search(element);
  bool less_than_2 = false;
  bool is_0 = false;
  bool was_left = false;
  bool was_right = false;
  if (node_to_rmv == nullptr) {
    return false;
  }
  // Node is root
  if (node_to_rmv->parent == nullptr) {
    if (!node_to_rmv->left_child && !node_to_rmv->right_child) {
      delete root;
      root = nullptr;
      return true;
    } // If it only has 1 child that child cannot have children because of AVL property
    else if (node_to_rmv->left_child != nullptr && node_to_rmv->right_child == nullptr) {
      typename BinaryTree<T>::Node* temp = root;
      root = root->left_child;
      delete temp;
      return true;
    }
    else if (node_to_rmv->right_child != nullptr && node_to_rmv->left_child == nullptr) {
      typename BinaryTree<T>::Node* temp = root;
      root = root->right_child;
      delete temp;
      return true;
    }
  }
  else {
    // Is a leaf
    if (!node_to_rmv->left_child && !node_to_rmv->right_child) {
      // Is a left child
      if (node_to_rmv->parent->left_child == node_to_rmv) {
	//////////////      node_to_rmv->parent->left_child = nullptr;
	less_than_2 = true;
	was_left = true;
	is_0 = true;
	to_delete = node_to_rmv;
	node_to_rmv->parent->left_child = nullptr;
      }
      // Is a right child
      else if (node_to_rmv->parent->right_child == node_to_rmv) {
	////////////      node_to_rmv->parent->right_child = nullptr;
	is_0 = true;
	was_right = true;
	less_than_2 = true;
	to_delete = node_to_rmv;
	node_to_rmv->parent->right_child = nullptr;
      }
    }
    // If node has only 1 child
    // Has a left child
    if (node_to_rmv->left_child != nullptr && node_to_rmv->right_child == nullptr) {
      // Is a left child
      if (node_to_rmv->parent->left_child == node_to_rmv) {
	node_to_rmv->parent->left_child = node_to_rmv->left_child;
	node_to_rmv->left_child->parent = node_to_rmv->parent;
	was_left = true;
	less_than_2 = true;
	to_delete = node_to_rmv;
      }
      // Is a right child
      else if (node_to_rmv->parent->right_child == node_to_rmv) {
	node_to_rmv->parent->right_child = node_to_rmv->left_child;
	node_to_rmv->left_child->parent = node_to_rmv->parent;
	was_right = true;
	less_than_2 = true;
	to_delete = node_to_rmv;
      }
    }
    // Has a right child
    else if (node_to_rmv->left_child == nullptr && node_to_rmv->right_child != nullptr) {
      // Is a left child
      if (node_to_rmv->parent->left_child == node_to_rmv) {
	node_to_rmv->parent->left_child = node_to_rmv->right_child;
	node_to_rmv->right_child->parent = node_to_rmv->parent;
	was_left = true;
	less_than_2 = true;
	to_delete = node_to_rmv;
      }
      // Is a right child
      else if (node_to_rmv->parent->right_child == node_to_rmv) {
	node_to_rmv->parent->right_child = node_to_rmv->right_child;
	node_to_rmv->right_child->parent = node_to_rmv->parent;
	was_right = true;
	less_than_2 = true;
	to_delete = node_to_rmv;
      }
    }
  }
  if (less_than_2 == false) {
    // The node has 2 children
    typename BinaryTree<T>::Node* right_ch = node_to_rmv->right_child;
    // Minimum value in right subtree
    least_in_right = find_min(right_ch);
    // Overwrite the data in node to remove
    node_to_rmv->data = least_in_right->data;
    // Bypassing old node with the data
    if (right_ch != least_in_right) {
      was_left = true;
      least_in_right->parent->left_child = least_in_right->right_child;
      if (least_in_right->right_child != nullptr) {
	least_in_right->right_child->parent = least_in_right->parent;
      }
    }
    else {
      was_right = true;
      right_ch->parent->right_child = right_ch->right_child;
      if (right_ch->right_child != nullptr) {
	right_ch->right_child->parent = right_ch->parent;
      }
    }
  }
  // Need to update the depths and check for imbalances
  temp = to_delete;
  /////////////////// Check if root is to be deleted
  ///// If special case, just change root pointer to new root //////////////////
  while (temp->parent != nullptr) {
    ////////////////////////////// Make sure to_delete is not involved in rebalancing
    // temp was/is a left child
    if (temp->parent->left_child == temp || was_left) {
      // Decrement left depth because here it was on the left path that the node was deleted
      int max = temp->depth_left > temp->depth_right ? temp->depth_left : temp->depth_right;
      if (temp == to_delete || max + 1 < temp->parent->depth_left) {///////////////////////)
	--(temp->parent->depth_left);
      }
      // If became too right heavy, attempt a rebalance
      if (temp->parent->depth_left - temp->parent->depth_right < -1) {
	// It turns out this will distinguish between case 3 and 4
	if (temp->parent->right_child->depth_left > temp->parent->right_child->depth_right) {
	  // Case 3 rotation
	  //////////////////// What if this is nullptr
	  if (temp->parent->parent != nullptr) {
	    if (temp->parent->parent->left_child == temp->parent) {
	      balance_tree(3, temp->parent->parent->left_child);
	      if (temp == to_delete) {
		delete temp;
	      }
	      break;
	    }
	    else {
	      balance_tree(3, temp->parent->parent->right_child);
	      if (temp == to_delete) {
		delete temp;
	      }
	      break;
	    }
	  }
	  else {
	    balance_tree(3, root);
	    if (temp == to_delete) {
	      delete temp;
	    }
	    break;
	  }
	}
	else if (temp->parent->right_child->depth_left <= temp->parent->right_child->depth_right) {
	  // Case 4 rotation
	  if (temp->parent->parent != nullptr) {
	    if (temp->parent->parent->left_child == temp->parent) {
	      balance_tree(4, temp->parent->parent->left_child);
	      if (temp == to_delete) {
		delete temp;
	      }
	      break;
	    }
	    else {
	      balance_tree(4, temp->parent->parent->right_child);
	      if (temp == to_delete) {
		delete temp;
	      }
	      break;
	    }
	  }
	  else {
	    balance_tree(4, root);
	    if (temp == to_delete) {
	      delete temp;
	    }
	    break;
	  }
	}
      }

    }
    // temp was/is a right child
    else if (temp->parent->right_child == temp || was_right) {
      // Decrement right depth because here it was on the right path that the node was deleted
      int max = temp->depth_left > temp->depth_right ? temp->depth_left : temp->depth_right;
      if (temp == to_delete || max + 1 < temp->parent->depth_right) {///////////////////////
	--(temp->parent->depth_right);
      }
      // If became too left heavy, attempt a rebalance
      if (temp->parent->depth_left - temp->parent->depth_right > 1) {
	// It turns out this will distinguish between case 1 and 2
	if (temp->parent->left_child->depth_left >= temp->parent->left_child->depth_right) {
	  // Case 1 rotation
	  if (temp->parent->parent != nullptr) {
	    if (temp->parent->parent->left_child == temp->parent) {
	      balance_tree(1, temp->parent->parent->left_child);
	      if (temp == to_delete) {
		delete temp;
	      }
	      break;
	    }
	    else {
	      balance_tree(1, temp->parent->parent->right_child);
	      if (temp == to_delete) {
		delete temp;
	      }
	      break;
	    }
	  }
	  else {
	    balance_tree(1, root);
	    if (temp == to_delete) {
	      delete temp;
	    }
	    break;
	  }
	}
	else if (temp->parent->left_child->depth_left < temp->parent->left_child->depth_right) {
	  // Case 2 rotation
	  if (temp->parent->parent != nullptr) {
	    if (temp->parent->parent->left_child == temp->parent) {
	      balance_tree(2, temp->parent->parent->left_child);
	      if (temp == to_delete) {
		delete temp;
	      }	      
	      break;
	    }
	    else {
	      balance_tree(2, temp->parent->parent->right_child);
	      if (temp == to_delete) {
		delete temp;
	      }	      
	      break;
	    }
	  }
	  else {
	    balance_tree(2, root);
	    if (temp == to_delete) {
	      delete temp;
	    }
	    break;
	  }
	}
      }
    }
    was_left = false;
    was_right = false;
    typename BinaryTree<T>::Node* temp2 = temp;
    temp = temp->parent;
    if (temp2 == to_delete) {
      delete temp2;
    }
  }
}

template <typename T>
typename BinaryTree<T>::Node* AVLTree<T>::find_min(typename BinaryTree<T>::Node* subtree_root) {
  // If no argument, use root as subtree's root
  if (!subtree_root) {
    subtree_root = root;
  }
  typename BinaryTree<T>::Node* temp = subtree_root;
  // Keep marching left until found last node on this path
  while (temp->left_child != nullptr) {
    temp = temp->left_child;
  }
  return temp;
}

template <typename T>
typename BinaryTree<T>::Node* AVLTree<T>::find_max(typename BinaryTree<T>::Node* subtree_root) {
  // If no argument, use root as subtree's root
  if (!subtree_root) {
    subtree_root = root;
  }
  typename BinaryTree<T>::Node* temp = subtree_root;
  // Keep marching right until found last node on this path
  while (temp->right_child != nullptr) {
    temp = temp->right_child;
  }
  return temp;
}

template <typename T>
typename BinaryTree<T>::Node* AVLTree<T>::get_successor(typename BinaryTree<T>::Node* n) {
  if (n == nullptr) {
    return nullptr;
  }
  typename BinaryTree<T>::Node* in_subtree = nullptr, * not_in_subtree = nullptr;
  // Next element (value based) is the smallest value in the right subtree
  if (n->right_child != nullptr) {
    in_subtree = find_min(n->right_child);
  }
  typename BinaryTree<T>::Node* temp = n, * temp2 = n->parent;
  typename BinaryTree<T>::Node* a = nullptr;
  while (temp2 != nullptr) {
    if (temp2->data < n->data && temp == temp2->left_child) {
      if (not_in_subtree != nullptr) {
	if (temp2->data > n->data && temp2->data < not_in_subtree->data) {
	  not_in_subtree = temp2;
	}
      }
      else {
	if (temp2->data > n->data) {
	  not_in_subtree = temp2;
	}	
      }
      a = inorder_traversal_for_succ(temp2->right_child, n->data);
    }
    else if (temp2->data > n->data && temp == temp2->right_child) {
      if (not_in_subtree != nullptr) {
	if (temp2->data > n->data && temp2->data < not_in_subtree->data) {
	  not_in_subtree = temp2;
	}
      }
      else {
	if (temp2->data > n->data) {
	  not_in_subtree = temp2;
	}	
      }
      a = inorder_traversal_for_succ(temp2->left_child, n->data);
    }
    else {
      if (not_in_subtree != nullptr) {
	if (temp2->data > n->data && temp2->data < not_in_subtree->data) {
	  not_in_subtree = temp2;
	}
      }
      else {
	if (temp2->data > n->data) {
	  not_in_subtree = temp2;
	}	
      }
    }
    if (a != nullptr) {
      if (not_in_subtree == nullptr) {
	not_in_subtree = a;
      }
      else if (not_in_subtree->data > a->data) {
	not_in_subtree = a;
      }
    }
    temp = temp2;
    temp2 = temp2->parent;
  }
  if (not_in_subtree != nullptr) {
    if (root->data > n->data && root->data < not_in_subtree->data) {
      not_in_subtree = root;
    }
  }
  else {
    if (root->data > n->data) {
      not_in_subtree = root;
    }
  }
  if (in_subtree != nullptr && not_in_subtree != nullptr) {
    return in_subtree->data < not_in_subtree->data ? in_subtree : not_in_subtree;
  }
  else if (in_subtree == nullptr) {
    return not_in_subtree;
  }
  else if (not_in_subtree == nullptr) {
    return in_subtree;
  }
  else {
    return nullptr;
  }
}

template <typename T>
typename BinaryTree<T>::Node* AVLTree<T>::get_predecessor(typename BinaryTree<T>::Node* n) {
  if (n == nullptr) {
    return nullptr;
  }
  typename BinaryTree<T>::Node* in_subtree = nullptr, * not_in_subtree = nullptr;
  // Next element (value based) is the smallest value in the right subtree
  if (n->left_child != nullptr) {
    in_subtree = find_max(n->left_child);
  }
  typename BinaryTree<T>::Node* temp = n, * temp2 = n->parent;
  typename BinaryTree<T>::Node* a = nullptr;
  while (temp2 != nullptr) {
    if (temp2->data < n->data && temp == temp2->left_child) {
      if (not_in_subtree != nullptr) {
	if (temp2->data < n->data && temp2->data > not_in_subtree->data) {
	  not_in_subtree = temp2;
	}
      }
      else {
	if (temp2->data < n->data) {
	  not_in_subtree = temp2;
	}	
      }
      a = rev_inorder_traversal_for_pred(temp2->right_child, n->data);
    }
    else if (temp2->data > n->data && temp == temp2->right_child) {
      if (not_in_subtree != nullptr) {
	if (temp2->data < n->data && temp2->data > not_in_subtree->data) {
	  not_in_subtree = temp2;
	}
      }
      else {
	if (temp2->data < n->data) {
	  not_in_subtree = temp2;
	}	
      }
      a = rev_inorder_traversal_for_pred(temp2->left_child, n->data);
    }
    else {
      if (not_in_subtree != nullptr) {
	if (temp2->data < n->data && temp2->data > not_in_subtree->data) {
	  not_in_subtree = temp2;
	}
      }
      else {
	if (temp2->data < n->data) {
	  not_in_subtree = temp2;
	}	
      }
    }
    if (a != nullptr) {
      if (not_in_subtree == nullptr) {
	not_in_subtree = a;
      }
      else if (not_in_subtree->data < a->data) {
	not_in_subtree = a;
      }
    }
    temp = temp2;
    temp2 = temp2->parent;
  }
  if (not_in_subtree != nullptr) {
    if (root->data < n->data && root->data > not_in_subtree->data) {
      not_in_subtree = root;
    }
  }
  else {
    if (root->data < n->data) {
      not_in_subtree = root;
    }
  }
  if (in_subtree != nullptr && not_in_subtree != nullptr) {
    return in_subtree->data > not_in_subtree->data ? in_subtree : not_in_subtree;
  }
  else if (in_subtree == nullptr) {
    return not_in_subtree;
  }
  else if (not_in_subtree == nullptr) {
    return in_subtree;
  }
  else {
    return nullptr;
  }
}

template <typename T>
const T& AVLTree<T>::get_node(typename BinaryTree<T>::Node* n) {
  return n->data;
}

template <typename T>
typename BinaryTree<T>::Node* AVLTree<T>::get_root() {
  return root;
}

template <typename T>
void AVLTree<T>::print_pre_order() {
  this->preorder(root);
}

template <typename T>
void AVLTree<T>::print_post_order() {
  this->postorder(root);
}

template <typename T>
void AVLTree<T>::print_in_order() {
  this->inorder(root);
}

template <typename T>
typename BinaryTree<T>::Node* AVLTree<T>::inorder_traversal_for_succ(typename BinaryTree<T>::Node* subtree_root, const T& element) {
  if (subtree_root == nullptr) {
    return nullptr;
  }
  inorder_traversal_for_succ(subtree_root->left_child, element);
  if (subtree_root->data > element) {
    return subtree_root;
  }
  inorder_traversal_for_succ(subtree_root->right_child, element);
}

template <typename T>
  typename BinaryTree<T>::Node* AVLTree<T>::rev_inorder_traversal_for_pred(typename BinaryTree<T>::Node* subtree_root, const T& element) {
 if (subtree_root == nullptr) {
    return nullptr;
  }
  inorder_traversal_for_succ(subtree_root->right_child, element);
  if (subtree_root->data < element) {
    return subtree_root;
  }
  inorder_traversal_for_succ(subtree_root->left_child, element);
}


template <typename T>
void AVLTree<T>::preorder_for_copying(typename BinaryTree<T>::Node* subtree_root, typename BinaryTree<T>::Node*& parent_) {
  if (subtree_root == nullptr) {
    return;
  }
  const typename BinaryTree<T>::Node*& left = subtree_root->left_child;
  const typename BinaryTree<T>::Node*& right = subtree_root->right_child;
  if (left != nullptr) {
    typename BinaryTree<T>::Node* new_node = new typename BinaryTree<T>::Node(left->data, parent_, nullptr, nullptr, left->depth_left, left->depth_right);
    parent_->left_child = new_node;
    preorder_for_copying(left, new_node);
  }
  if (right != nullptr) {
    typename BinaryTree<T>::Node* new_node = new typename BinaryTree<T>::Node(right->data, parent_, nullptr, nullptr, right->depth_left, right->depth_right);
    parent_->right_child = new_node;
    preorder_for_copying(right, new_node);
  }
}

template <typename T>
void AVLTree<T>::postorder_for_deleting(typename BinaryTree<T>::Node* r) {
  if (r == nullptr) {
    return;
  }
  postorder_for_deleting(r->left_child);
  postorder_for_deleting(r->right_child);
  delete r;
}

template <typename T>
void AVLTree<T>::balance_tree(int imb_case, typename BinaryTree<T>::Node*& subtree_root) {
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
void AVLTree<T>::left_rotation(typename BinaryTree<T>::Node*& subtree_root) {
  typename BinaryTree<T>::Node* subtree_roots_parent = subtree_root->parent;
  bool is_left = true;
  // If subtree root is not the actual root of the entire tree (thus it has a parent)
  if (subtree_roots_parent != nullptr) {
    // Subtree root is a left child
    if (subtree_root == subtree_roots_parent->left_child) {
      ;
    }
    else {
      is_left = false;
    }
  }
  typename BinaryTree<T>::Node* old_subtree_root = subtree_root;
  typename BinaryTree<T>::Node* old_subtree_root_right_child = subtree_root->right_child;
  typename BinaryTree<T>::Node* old_subtree_root_right_child_left_child = old_subtree_root_right_child->left_child;
  typename BinaryTree<T>::Node* old_subtree_root_right_grand = old_subtree_root_right_child->right_child;

  old_subtree_root_right_child->right_child = old_subtree_root_right_grand;
  old_subtree_root_right_child->left_child = old_subtree_root;

  if (subtree_roots_parent != nullptr) {
    if (is_left) {
      subtree_roots_parent->left_child = old_subtree_root_right_child;
    }
    else {
      subtree_roots_parent->right_child = old_subtree_root_right_child;
    }
  }
  if (old_subtree_root_right_grand != nullptr) {
    old_subtree_root_right_grand->parent = old_subtree_root_right_child;
  }
  old_subtree_root->parent = old_subtree_root_right_child;
  if (subtree_roots_parent != nullptr) {
    old_subtree_root_right_child->parent = subtree_roots_parent;
  }
  old_subtree_root->right_child = old_subtree_root_right_child_left_child;

  if (old_subtree_root->right_child != nullptr) {
    if (old_subtree_root->right_child->depth_left >= old_subtree_root->right_child->depth_right) {
      old_subtree_root->depth_right = 1 + old_subtree_root->right_child->depth_left;
    }
    else {
      old_subtree_root->depth_right = 1 + old_subtree_root->right_child->depth_right;
    }
  }
  else {
    old_subtree_root->depth_right = -1;
  }

  if (old_subtree_root_right_child_left_child != nullptr) {
    old_subtree_root_right_child_left_child->parent = old_subtree_root;
  }
  subtree_root = old_subtree_root_right_child;
  subtree_root->parent = subtree_roots_parent;
  if (subtree_roots_parent != nullptr) {
    if (is_left) {
      subtree_roots_parent->left_child = subtree_root;
    }
    else {
      subtree_roots_parent->right_child = subtree_root;
    }
  }
  if (old_subtree_root->depth_left >= old_subtree_root->depth_right) {
    subtree_root->depth_left = 1 + old_subtree_root->depth_left;
  }
  else {
    subtree_root->depth_left = 1 + old_subtree_root->depth_right;
  }  
}

template <typename T>
void AVLTree<T>::right_rotation(typename BinaryTree<T>::Node*& subtree_root) {
  typename BinaryTree<T>::Node* subtree_roots_parent = subtree_root->parent;
  bool is_left = true;
  // If subtree root is not the actual root of the entire tree (thus it has a parent)
  if (subtree_roots_parent != nullptr) {
    // Subtree root is a left child
    if (subtree_root == subtree_roots_parent->left_child) {
      ;
    }
    else {
      is_left = false;
    }
  }
  typename BinaryTree<T>::Node* old_subtree_root = subtree_root;
  typename BinaryTree<T>::Node* old_subtree_root_left_child = subtree_root->left_child;
  typename BinaryTree<T>::Node* old_subtree_root_left_child_right_child = old_subtree_root_left_child->right_child;
  typename BinaryTree<T>::Node* old_subtree_root_left_grand = old_subtree_root_left_child->left_child;

  old_subtree_root_left_child->left_child = old_subtree_root_left_grand;
  old_subtree_root_left_child->right_child = old_subtree_root;

  if (subtree_roots_parent != nullptr) {
    if (is_left) {
      subtree_roots_parent->left_child = old_subtree_root_left_child;
    }
    else {
      subtree_roots_parent->right_child = old_subtree_root_left_child;
    }
  }
  if (old_subtree_root_left_grand != nullptr) {
    old_subtree_root_left_grand->parent = old_subtree_root_left_child;
  }
  old_subtree_root->parent = old_subtree_root_left_child;
  if (subtree_roots_parent != nullptr) {
    old_subtree_root_left_child->parent = subtree_roots_parent;
  }
  old_subtree_root->left_child = old_subtree_root_left_child_right_child;

  if (old_subtree_root->left_child != nullptr) {
    if (old_subtree_root->left_child->depth_left >= old_subtree_root->left_child->depth_right) {
      old_subtree_root->depth_left = 1 + old_subtree_root->left_child->depth_left;
    }
    else {
      old_subtree_root->depth_left = 1 + old_subtree_root->left_child->depth_right;
    }
  }
  else {
    old_subtree_root->depth_left = -1;
  }
  
  if (old_subtree_root_left_child_right_child != nullptr) {
    old_subtree_root_left_child_right_child->parent = old_subtree_root;
  }
  
  subtree_root = old_subtree_root_left_child;
  subtree_root->parent = subtree_roots_parent;
  if (subtree_roots_parent != nullptr) {
    if (is_left) {
      subtree_roots_parent->left_child = subtree_root;
    }
    else {
      subtree_roots_parent->right_child = subtree_root;
    }
  }

  if (old_subtree_root->depth_left >= old_subtree_root->depth_right) {
    subtree_root->depth_right = 1 + old_subtree_root->depth_left;
  }
  else {
    subtree_root->depth_right = 1 + old_subtree_root->depth_right;
  }
}

template <typename T>
void AVLTree<T>::left_right_double_rotation(typename BinaryTree<T>::Node*& subtree_root) {
  left_rotation(subtree_root->left_child);
  right_rotation(subtree_root);
}

template <typename T>
void AVLTree<T>::right_left_double_rotation(typename BinaryTree<T>::Node*& subtree_root) {
  right_rotation(subtree_root->right_child);
  left_rotation(subtree_root);
}
