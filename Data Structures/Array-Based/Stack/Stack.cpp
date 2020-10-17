template <typename T>
Stack<T>::Stack(int cap) : top_(-1) {
  this->cap = cap;
  data = new T[cap];
}

template <typename T>
void Stack<T>::push(const T& element) {
  if (top_ + 1 >= cap) {
    resize();
  }
  data[++top_] = element;
}

template <typename T>
T Stack<T>::top() {
  if (top_ == -1) {
    return T();
  }
  return data[top_];
}

template <typename T>
void Stack<T>::pop() {
  if (top_ > -1) {
    --top_;
  }
}

template <typename T>
void Stack<T>::resize() {
  T* temp = new T[cap];
  for (int i = 0; i < cap; ++i) {
    temp[i] = data[i];
  }
  delete [] data;
  data = new T[2 * cap];
  for (int i = 0; i < cap; ++i) {
    data[i] = temp[i];
  }
  delete [] temp;
  cap *= 2;
}
