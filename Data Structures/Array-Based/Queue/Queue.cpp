template <typename T>
Queue<T>::Queue(int cap) : front(0), back(-1) {
  this->cap = cap;
  data = new T[cap];
  num_elements = 0;
}

template <typename T>
void Queue<T>::push(const T& element) {
  if (num_elements == cap) {
    resize();
  }
  (++back) %= cap;
  data[back] = element;
  ++num_elements;
}

template <typename T>
T Queue<T>::front_() {
  if (back == front - 1 && num_elements == 0) {
    return T();
  }
  else {
    return data[front];
  }
}

template <typename T>
T Queue<T>::back_() {
  if (back == front - 1 && num_elements == 0) {
    return T();
  }
  else {
    return data[back];
  }
}

template <typename T>
void Queue<T>::pop() {
  if (num_elements == 0) {
    return;
  }
  (++front) %= cap;
  --num_elements;
}

template <typename T>
void Queue<T>::resize() {
  T* temp = new T[cap * 2];
  for (int i = 0; i < cap; ++i) {
    temp[i] = data[(i + front) % cap];
  }
  front = 0;
  back = num_elements - 1;
  cap *= 2;
  delete [] data;
  data = new T[cap];
  for (int i = 0; i < cap; ++i) {
    data[i] = temp[i];
  }
  delete [] temp;
}
