#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename Type>
class List {
 public:
  virtual ~List() = 0;
  // Insert element at beginning of list
  virtual bool insert_beg(const Type& datum) = 0;
  // Insert element at end of list
  virtual bool insert_end(const Type& datum) = 0;
  // Insert element into a sorted list
  virtual bool insert_into_sorted(const Type& datum) = 0;
  // Insert element at given index
  virtual bool insert(int index, const Type& datum) = 0;
  // Remove element from beginning of list
  virtual bool remove_beg() = 0;
  // Remove element from end of list
  virtual bool remove_end() = 0;
  // Remove element with given index
  virtual bool remove(int index) = 0;
  // Remove data element
  virtual bool remove_element(const Type& datum) = 0;
  // Find the kth element
  virtual Type& find_kth(int index) = 0;
  // Find index of data element
  virtual int find_element(const Type& datum) = 0;
  // Move present pointer forward
  virtual bool move_next() = 0;
  // Move present pointer backwards
  virtual bool move_prev() = 0;
  // Set an element at a given index to a new data element
  virtual bool set(int index, const Type& datum) = 0;
  // Print list
  virtual void print() const = 0;
  // Set whether or not the list is sorted
  virtual void set_is_sorted() = 0;
  // Check if the listt is sorted
  virtual bool check_is_sorted() const = 0;
  // Get the max element
  virtual Type get_max() = 0;
  // Get the min element
  virtual Type get_min() = 0;
  // Get the sum of all the elements
  virtual Type get_sum() = 0;
  // Get the average of all the elements
  virtual double get_avg() = 0;
  // Reverse all the elements
  virtual void reverse() = 0;
  // Rotate the array to the left by a certain amount
  virtual void left_rotate(int shift_amount) = 0;
  // Rotate the array to the right by a certain amount
  virtual void right_rotate(int shift_amount) = 0;
  // Merge two sorted lists (this one becomes result)
  virtual bool merge_sorted(const List<Type>& other) = 0;
  // Changes list to a set
  virtual List<Type>* to_set() const = 0;
  // Finds the union of two lists
  virtual List<Type>* union_list(const List<Type>& other) = 0;
  // Finds the intersection of two lists
  virtual List<Type>* intersection_list(const List<Type>& other) = 0;
  // Finds the difference (non-common elements) of two lists
  virtual List<Type>* difference_list(const List<Type>& other) = 0;
  // Returns pointer to beginning of list
  Type* get_first() const;
  // Returns pointer to present position of list
  Type* get_present() const;
  // Returns index of present position of list
  ptrdiff_t get_present_index() const;
  // Returns size of list
  int get_size() const;
// Also add sort function
protected:
  // Allocates memory with given capacity
  virtual void allocate(int capacity) = 0;
  // Swaps two elements
  virtual inline void swap(Type& f, Type& s) = 0;
  Type* first {nullptr}, * present {nullptr};
  int size {0};
  bool is_sorted = false;
};

template <typename Type>
List<Type>::~List() {
  
}

template <typename Type>
Type* List<Type>::get_first() const {
  return first;
}

template <typename Type>
Type* List<Type>::get_present() const {
  return present;
}


template <typename Type>
ptrdiff_t List<Type>::get_present_index() const {
  if (first == nullptr or present == nullptr) {
    return -1;
  }
  else {
    return present - first;
  }
}

template <typename Type>
int List<Type>::get_size() const {
  return size;
}

// LIST_H
#endif
