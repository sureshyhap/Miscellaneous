#include <iostream>
#include <stack>
#include <cstring>

bool is_balanced(char* exp);

int main(int argc, char* argv[]) {
  char* exp1 = new char[4 + 1];
  strcpy(exp1, "[(])");
  std::cout << is_balanced(exp1) << std::endl;
  char* exp2 = new char[10 + 1];
  strcpy(exp2, "({[]()}[])");
  std::cout << is_balanced(exp2) << std::endl;
  return 0;
}

bool is_balanced(char* exp) {
  std::stack<char> s;
  for (int i = 0; exp[i] != '\0'; ++i) {
    // Character is not an operand
    if (exp[i] != '(' && exp[i] != ')' &&
	exp[i] != '{' && exp[i] != '}' &&
	exp[i] != '[' && exp[i] != ']') {
      continue;
    }
    // Is a left operand
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      s.push(exp[i]);
    }
    // Is a right operand
    else {
      // No matching left operand
      if (s.empty() == true) {
	return false;
      }
      else {
	// If left operand matches right operand
	if ((exp[i] == ')' && s.top() == '(') ||
	    (exp[i] == '}' && s.top() == '{') ||
	    (exp[i] == ']' && s.top() == '[')) {
	  s.pop();
	}
	// Left operand does not match right operand
	else {
	  return false;
	}
      }
    }
  }
  // If remaining left operand in stack then there was
  // no matching right operand
  if (s.empty() == false) {
    return false;
  }
  else {
    return true;
  }
}
