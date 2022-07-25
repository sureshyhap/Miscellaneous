//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

//const int BITS_PER_BIN = 8;
const int PASSES = 4;
const int VALUE_RANGE = 256;

void lsd_radix_sort(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {122858245, 80533928, 409915128, 13911061, 976635801, 385368233, 571578923, 187456621};
  int size = sizeof(a) / sizeof(int);
  lsd_radix_sort(a, size);
  for (int i = 0; i < size; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

struct Node {
  Node(int val = int(), Node* n = nullptr, Node* e = nullptr) : value(val), next(n), end(e) {}
  int value;
  Node* next, * end;
};

void lsd_radix_sort(int a[], int n) {
  Node* bins[VALUE_RANGE];
  for (int i = 0; i < VALUE_RANGE; ++i) {
    bins[i] = new Node;
  }
  for (int div_by_range = 0; div_by_range < PASSES; ++div_by_range) {
    for (int i = 0; i < n; ++i) {
      Node* p = new Node(a[i]);
      int temp_value = a[i] / pow(VALUE_RANGE, div_by_range);
      int index = temp_value % VALUE_RANGE;
      Node* temp = bins[index]->end;
      if (temp == nullptr) {
	bins[index]->next = p;
	bins[index]->end = p;
      }
      else {
	temp->next = p;
	bins[index]->end = p;
      }
    }
    /////////// Most likely problem below
    for (int i = 0, k = 0; i < VALUE_RANGE; ++i) {
      Node* temp = bins[i];
      while (temp->next != nullptr) {
	a[k++] = temp->next->value;
	Node* temp2 = temp->next;
	if (temp2->next == nullptr) {
	  delete temp2;
	  break;
	}
	temp = temp2;
      }
      bins[i]->next = nullptr;
      bins[i]->end = nullptr;
    }
  }
}

//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
//////////////////////////////////////// CHECK WITH NEGATIVE INTEGERS!! /////////////////////////////////////////////////////
