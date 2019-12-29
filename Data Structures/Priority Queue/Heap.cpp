template <typename T>
Heap<T>::Heap() : BinaryTree<T>() {
}

template <typename T>
Heap<T>::Heap(const Heap& h) : BinaryTree<T>(h) {
}

template <typename T>
Heap<T>::~Heap() {
}

template <typename T>
typename Heap<T>::Heap& Heap<T>::operator=(const Heap& h) {
  operator=(h);
}

template <typename T>
bool Heap<T>::insert(const T& element, const T& parent_element, bool is_left) {
  typename BinaryTree<T>::Node* new_node = new typename BinaryTree<T>::Node(element);
  this->tree.push_back(new_node);
  percolate_up();
  return true;
}

template <typename T>
bool Heap<T>::remove(const T& element) {
  if (this->tree.empty()) {
    return false;
  }
  else {
    this->tree.front() = this->tree.back();
    this->tree.pop_back();
    percolate_down();
    return true;
  }
}

template <typename T>
void Heap<T>::percolate_up() {
  int size = this->tree.size();
  for (int i = size - 1; i > 0; i = (i - 1) / 2) {
    int parent_index = (i - 1) / 2;
    if (this->tree[i]->data > this->tree[parent_index]->data) {
      T temp = this->tree[parent_index]->data;
      this->tree[parent_index]->data = this->tree[i]->data;
      this->tree[i]->data = temp;
    }
    else {
      break;
    }
  }
}

template <typename T>
void Heap<T>::percolate_down() {
  int size = this->tree.size();
  int i = 0;
  for (; ((2 * i) + 2) < size; i = (2 * i) + 2) {
    int larger_child_index = (2 * i) + 2;
    if (this->tree[i]->data < this->tree[larger_child_index]->data) {
      T temp = this->tree[larger_child_index]->data;
      this->tree[larger_child_index]->data = this->tree[i]->data;
      this->tree[i]->data = temp;
    }
    else {
      break;
    }
  }
  int smaller_child_index = (2 * i) + 1;
  if (((2 * i) + 1 < size) && this->tree[i]->data < this->tree[smaller_child_index]->data) {
    T temp = this->tree[smaller_child_index]->data;
    this->tree[smaller_child_index]->data = this->tree[i]->data;
    this->tree[i]->data = temp;
  }
}
