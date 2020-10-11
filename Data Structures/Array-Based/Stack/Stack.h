#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
 public:
  Stack(int cap = 1);
  void push(const T& element);
  T top();
  void pop();
 protected:
  void resize();
  T* data;
  int top_, cap;
};

#include "Stack.cpp"

#endif // STACK_H
