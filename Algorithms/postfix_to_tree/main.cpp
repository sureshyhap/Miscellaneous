#include <iostream>
#include "Tree.h"
#include <string>
#include <stack>
#include <list>

Tree<char>* pftt(std::string exp);

int main(int argc, char* argv[]) {
  std::string s = "ab+cde+**";
  int len = s.length();
  Tree<char>* expression_tree = pftt(s);
  expression_tree->print();
  return 0;
}

Tree<char>* pftt(std::string exp) {
  std::stack<Tree<char>*> st;
  int len = exp.length();
  for (int i = 0; i < len; ++i) {
    // If operator
    if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
      Tree<char>* right_operand = st.top();
      st.pop();
      Tree<char>* left_operand = st.top();
      st.pop();
      std::list<Tree<char>*> operands;
      operands.push_back(left_operand);
      operands.push_back(right_operand);
      Tree<char>* new_tree = new Tree<char>(exp[i], operands);
      st.push(new_tree);
    }
    // If operand
    else {
      Tree<char>* singleton = new Tree<char>(exp[i]);
      st.push(singleton);
    }
  }
  return st.top();
}
