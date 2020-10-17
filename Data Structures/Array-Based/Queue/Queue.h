#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
 public:
  Queue(int cap = 1);
  void push(const T& element);
  T front_();
  T back_();
  void pop();
 protected:
  void resize();
  T* data;
  int cap;
  int num_elements;
  int front, back;
};

#include "Queue.cpp"

#endif // QUEUE_H
