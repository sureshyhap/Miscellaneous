#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Heap.h"

template <typename T>
class Priority_Queue {
 public:
  Priority_Queue();
  Priority_Queue(const Priority_Queue& pq);
  ~Priority_Queue();
  Priority_Queue& operator=(const Priority_Queue& pq);
  int get_size() const;
  bool is_empty() const;
  const T& top() const;
  void push(const T& element);
  void pop();
  void print_level();
 protected:
  Heap<T> data;
  private:
};

#include "Priority_Queue.cpp"

#endif //PRIORITY_QUEUE_H
