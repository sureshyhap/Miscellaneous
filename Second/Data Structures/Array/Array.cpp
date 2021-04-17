#include <iostream>
#include "Array.h"
#include <stdexcept>

template <typename Type2>
std::ostream& operator<<(std::ostream& os, const Array<Type2>& arr) {
  for (int i {0}; i < arr.size; ++i) {
    os << (arr.first)[i] << ' ';
  }
  return os;
}

template <typename Type>
Array<Type>::Array() {
  
}

template <typename Type>
Array<Type>::Array(const List<Type>& other) {
  delete [] this->first;
  this->first = {nullptr};
  allocate(other.get_size());
  this->present = {this->first};
  this->size = {other.get_size()};
  for (int i {0}; i < this->size; ++i) {
    this->first[i] = {other.get_first()[i]};
  }
  set_is_sorted();
}

template <typename Type>
Array<Type>::Array(Type arr[], int n) {
  this->first = new Type[n];
  for (int i = 0; i < n; ++i) {
    this->first[i] = arr[i];
  }
  this->present = this->first;
  this->size = n;
  set_is_sorted();
}

template <typename Type>
Array<Type>& Array<Type>::operator=(const Array<Type>& other) {
  delete [] this->first;
  this->first = {nullptr};
  allocate(other.size);
  this->present = {this->first};
  this->size = {other.size};
  for (int i {0}; i < this->size; ++i) {
    this->first[i] = {other.first[i]};
  }
  set_is_sorted();
  return *this;
}

template <typename Type>
Array<Type>::~Array() {
  delete [] this->first;
  this->first = {nullptr};
  this->present = {nullptr};
  this->size = {0};
}

template <typename Type>
bool Array<Type>::insert_beg(const Type& datum) {
  return insert(0, datum);
}

template <typename Type>
bool Array<Type>::insert_end(const Type& datum) {
  return insert(this->size, datum);
}

template <typename Type>
bool Array<Type>::insert_into_sorted(const Type& datum) {
  if (!this->is_sorted) {
    return false;
  }
  else {
    return insert(-1, datum);
  }
}

template <typename Type>
bool Array<Type>::insert(int index, const Type& datum) {
  if (index > this->size or (index < 0 and index != -1)) {
    return false;
  }
  Type* copy {this->first};
  ptrdiff_t present_index {-1};
  if (this->first != nullptr and this->present != nullptr) {
    present_index = {this->present - this->first};
  }
  this->first = {nullptr};
  this->present = {nullptr};
  ++(this->size);
  allocate(this->size);
  // index == -1 means insert datum into a sorted list
  int i {0};
  if (index == -1) {
    while (datum >= copy[i]) {
      this->first[i] = {copy[i]};
      ++i;
    }
  }
  else {
    // Copy first part of array
    for (i = {0}; i < index; ++i) {
      this->first[i] = {copy[i]};
    }
  }
  // Copy data into index spot
  this->first[i++] = {datum};
  // Copy last part of array
  for (; i < this->size; ++i) {
    this->first[i] = {copy[i - 1]};
  }
  // Either first or present were nullptr so reset present
  if (present_index == -1) {
    this->present = {this->first};
  }
  // If element inserted was after present, present stays the same
  else if (present_index < index) {
    this->present = {this->first + present_index};
  }
  // Otherwise present shifts over to stay at the element it was pointing to
  else {
    this->present = {this->first + present_index + 1};
  }
  delete [] copy;
  return true;
}

template <typename Type>
bool Array<Type>::remove_beg() {
  return remove(0);
}

template <typename Type>
bool Array<Type>::remove_end() {
  return remove(this->size - 1);
}

template <typename Type>
bool Array<Type>::remove(int index) {
  if (index >= this->size or index < 0) {
    return false;
  }
  Type* copy {this->first};
  // Keeping track of present's position for later
  ptrdiff_t present_index {this->present - this->first};
  this->first = {new Type[--(this->size)]};
  for (int i {0}; i < index; ++i) {
    this->first[i] = copy[i];
  }
  for (int i {index}; i < this->size; ++i) {
    this->first[i] = copy[i + 1];
  }
  // Present's item was removed
  if (present_index == index) {
    this->present = this->first;
  }
  // Present is unaffected if the index of the removed element
  // is after its own
  else if (present_index < index) {
    this->present = this->first + present_index;
  }
  // Present shifts over to the left if the element
  // removed was to its left
  else {
    this->present = this->first + present_index - 1;
  }
  delete [] copy;
  return true;
}

template <typename Type>
bool Array<Type>::remove_element(const Type& datum) {
  return remove(find_element(datum));
}

template <typename Type>
Type& Array<Type>::find_kth(int index) {
  try {
    if (index >= this->size or index < 0) {
      throw std::runtime_error("Invalid index");
    }
  }
  catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  return this->first[index];
}

template <typename Type>
int Array<Type>::find_element(const Type& datum) {
  if (!this->is_sorted) {
    std::cout << "Hello" << '\n';
    return linear_search(datum);
  }
  else {
    std::cout << "World" << '\n';
    return binary_search(datum);
  }
}

template <typename Type>
bool Array<Type>::move_next() {
  if (this->present == nullptr) {
    return false;
  }
  ptrdiff_t present_index {this->present - this->first};
  if (present_index == this->size - 1) {
    return false;
  }
  else {
    ++this->present;
    return true;
  }
}

template <typename Type>
bool Array<Type>::move_prev() {
  if (this->present == nullptr) {
    return false;
  }

  ptrdiff_t present_index {this->present - this->first};
  if (present_index == 0) {
    return false;
  }
  else {
    --this->present;
    return true;
  }
}

template <typename Type>
bool Array<Type>::set(int index, const Type& datum) {
  if (index >= this->size or index < 0) {
    return false;
  }
  this->first[index] = {datum};
  return true;
}

template <typename Type>
void Array<Type>::print() const {
  std::cout << *this << '\n';
}

template <typename Type>
void Array<Type>::set_is_sorted() {
  for (int i = 1; i < this->size; ++i) {
    if (this->first[i] < this->first[i - 1]) {
      this->is_sorted = false;
      return;
    }
  }
  this->is_sorted = true;
  return;
}

template <typename Type>
bool Array<Type>::check_is_sorted() const {
  return this->is_sorted;
}

template <typename Type>
Type Array<Type>::get_max() {
  try {
    if (!this->size) {
      throw std::runtime_error("Empty array");
    }
    else if (this->is_sorted) {
      return this->first[this->size - 1];
    }
    else {
      int max_index = {0};
      for (int i = {1}; i < this->size; ++i) {
	if (this->first[i] > this->first[max_index]) {
	  max_index = {i};
	}
      }
      return this->first[max_index];
    }
  }
  catch (const std::runtime_error& e) {
    std::cerr << e.what();
    exit(1);
  }
}

template <typename Type>
Type Array<Type>::get_min() {
  try {
    if (!this->size) {
      throw std::runtime_error("Empty array");
    }
    else if (this->is_sorted) {
      return this->first[0];
    }
    else {
      int min_index = {0};
      for (int i = {1}; i < this->size; ++i) {
	if (this->first[i] < this->first[min_index]) {
	  min_index = {i};
	}
      }
      return this->first[min_index];
    }
  }
  catch (const std::runtime_error& e) {
    std::cerr << e.what();
    exit(1);
  }
}

template <typename Type>
Type Array<Type>::get_sum() {
  Type sum = {Type()};
  for (int i = {0}; i < this->size; ++i) {
    sum += this->first[i];
  }
  return sum;
}

template <typename Type>
double Array<Type>::get_avg() {
  if (!this->size) {
    return Type();
  }
  Type sum = get_sum();
  return static_cast<double>(sum) / this->size;
}

template <typename Type>
void Array<Type>::reverse() {
  for (int i = {0}; i < this->size / 2; ++i) {
    swap(this->first[i], this->first[this->size - i - 1]);
  }
}

template <typename Type>
void Array<Type>::left_rotate(int shift_amount) {
  Type* temp = new Type[this->size];
  int j = {0};
  for (int i = {shift_amount}; i < this->size; ++i, ++j) {
    temp[j] = this->first[i];
  }
  for (int i = {0}; j < this->size; ++i, ++j) {
    temp[j] = this->first[i];
  }
  for (int i = {0}; i < this->size; ++i) {
    this->first[i] = temp[i];
  }
  delete [] temp;
}

template <typename Type>
void Array<Type>::right_rotate(int shift_amount) {
  Type* temp = new Type[this->size];

  int i = {0};
  for (int j = {shift_amount}; j < this->size; ++i, ++j) {
    temp[j] = this->first[i];
  }
  for (int j = {0}; i < this->size; ++i, ++j) {
    temp[j] = this->first[i];
  }
  for (int j = {0}; j < this->size; ++j) {
    this->first[j] = temp[j];
  }
  delete [] temp;
}

template <typename Type>
bool Array<Type>::merge_sorted(const List<Type>& other) {
  // If either of the arrays are not sorted, cannot perform merge
  if (!this->is_sorted or !other.check_is_sorted()) {
    return false;
  }
  Type* result = new Type[this->size + other.get_size()];
  int i = 0, j = 0, k = 0;
  for (; i < this->size and j < other.get_size(); ) {
    if (this->first[i] <= other.get_first()[j]) {
      result[k++] = this->first[i++];
    }
    else {
      result[k++] = other.get_first()[j++];
    }
  }
  if (i == this->size) {
    while (j < other.get_size()) {
      result[k++] = other.get_first()[j++];
    }
  }
  else if (j == other.get_size()) {
    while (i < this->size) {
      result[k++] = this->first[i++];
    }
  }
  delete [] this->first;
  this->first = nullptr;
  this->present = nullptr;
  this->size += other.get_size();
  this->is_sorted = true;
  this->first = result;
  return true;
}

template <typename Type>
List<Type>* Array<Type>::to_set() const {
  if (!this->size) {
    return nullptr;
  }
  Type* temp = new Type[this->size];
  temp[0] = this->first[0];
  int temp_size = 1;
  bool found = false;
  for (int i = 1; i < this->size; ++i) {
    for (int j = 0; j < temp_size; ++j) {
      if (temp[j] == this->first[i]) {
	found = true;
	break;
      }
    }
    if (!found) {
      temp[temp_size++] = this->first[i];
    }
    else {
      found = false;
    }
  }
  Type* temp2 = new Type[temp_size];
  for (int i = 0; i < temp_size; ++i) {
    temp2[i] = temp[i];
  }
  delete [] temp;
  List<Type>* result = new Array<Type>(temp2, temp_size);
  return result;
}

template <typename Type>
List<Type>* Array<Type>::union_list(const List<Type>& other) {
  int total = this->get_size() + other.get_size();
  Type* temp = new Type[total];
  for (int i = 0; i < this->get_size(); ++i) {
    temp[i] = this->get_first()[i];
  }
  for (int i = 0; i < other.get_size(); ++i) {
    temp[this->get_size() + i] = other.get_first()[i];
  }
  Array<Type> t(temp, total);
  return t.to_set();
}

template <typename Type>
List<Type>* Array<Type>::intersection_list(const List<Type>& other) {
  if (!this->get_size() or !other.get_size()) {
    return nullptr;
  }
  int bigger_size = ((this->get_size() > other.get_size()) ? this->get_size() : other.get_size());
  Type* temp = new Type[bigger_size];
  int temp_size = 0;
  for (int i = 0; i < this->get_size(); ++i) {
    for (int j = 0; j < other.get_size(); ++j) {
      if (this->get_first()[i] == other.get_first()[j]) {
	temp[temp_size++] = this->get_first()[i];
	break;
      }
    }
  }
  Type* temp2 = new Type[temp_size];
  for (int i = 0; i < temp_size; ++i) {
    temp2[i] = temp[i];
  }
  delete [] temp;
  List<Type>* temp2_obj = new Array<Type>(temp2, temp_size);
  return temp2_obj->to_set();
}

template <typename Type>
List<Type>* Array<Type>::difference_list(const List<Type>& other) {




  if (!this->get_size() or !other.get_size()) {
    return nullptr;
  }
  int bigger_size = ((this->get_size() > other.get_size()) ? this->get_size() : other.get_size());
  Type* temp = new Type[bigger_size];
  int temp_size = 0;
  bool found = false;
  for (int i = 0; i < this->get_size(); ++i) {
    for (int j = 0; j < other.get_size(); ++j) {
      if (this->get_first()[i] == other.get_first()[j]) {
	found = true;
	break;
      }
    }
    if (!found) {
      temp[temp_size++] = this->get_first()[i];
    }
    else {
      found = false;
    }
  }
  Type* temp2 = new Type[temp_size];
  for (int i = 0; i < temp_size; ++i) {
    temp2[i] = temp[i];
  }
  delete [] temp;
  List<Type>* temp2_obj = new Array<Type>(temp2, temp_size);
  return temp2_obj->to_set();




  
}

template <typename Type>
void Array<Type>::allocate(int capacity) {
  try {
    this->first = {new Type[capacity]};
  }
  catch (const std::bad_alloc& e) {
    std::cout << e.what() << '\n';
    exit(1);
  }
}

template <typename Type>
void Array<Type>::swap(Type& f, Type& s) {
  Type temp = f;
  f = s;
  s = temp;
}
 
template <typename Type>
int Array<Type>::linear_search(const Type& datum) {
  for (int i {0}; i < this->size; ++i) {
    if (datum == this->first[i]) {
      return i;
    }
  }
  return -1;  
}

template <typename Type>
int Array<Type>::binary_search(const Type& datum) {
  int left = 0, right = this->size - 1;
 top:
  if (left <= right) {
    int mid = (left + right) / 2;
    if (this->first[mid] == datum) {
      return mid;
    }
    else if (this->first[mid] < datum) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
    goto top;
  }
  else {
    return -1;
  }
}

template class Array<int>;
