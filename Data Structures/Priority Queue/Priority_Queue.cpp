template <typename T>
Priority_Queue<T>::Priority_Queue() {
  data;
}

template <typename T>
Priority_Queue<T>::Priority_Queue(const Priority_Queue& pq) {
  data = pq.data;
}

template <typename T>
Priority_Queue<T>::~Priority_Queue() {
}

template <typename T>
typename Priority_Queue<T>::Priority_Queue& Priority_Queue<T>::operator=(const Priority_Queue& pq) {
  data = pq.data;
}

template <typename T>
int Priority_Queue<T>::get_size() const {
  return data.tree.size();
}

template <typename T>
bool Priority_Queue<T>::is_empty() const {
  return data.tree.empty();
}

template <typename T>
const T& Priority_Queue<T>::top() const {
  return data.tree.front();
}

template <typename T>
void Priority_Queue<T>::push(const T& element) {
  data.insert(element);
}

template <typename T>
void Priority_Queue<T>::pop() {
  data.remove();
}

template <typename T>
void Priority_Queue<T>::print_level() {
  (this->data).BinaryTree<T>::print_level_order();
}
