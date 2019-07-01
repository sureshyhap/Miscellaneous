#include <iostream>
#include <string>
#include <stack>
#include <sstream>

double eval_postfix(std::string expression);

int main(int argc, char* argv[]) {
  std::string str = "53+84-*";
  std::cout << eval_postfix(str);
  return 0;
}

double eval_postfix(std::string expression) {
  std::stack<double> s;
  int len = expression.length();
  for (int i = 0; i < len; ++i) {
    if (expression[i] == '+' ||
	expression[i] == '-' ||
	expression[i] == '*' ||
	expression[i] == '/') {
      if (s.size() < 2) {
	return 0.0; /////////////// Make this better
      }
      else {
	double right_operand = s.top();
	s.pop();
	double left_operand = s.top();
	s.pop();
	double result = double();
	switch (expression[i]) {
	case '+':
	  result = left_operand + right_operand;
	  break;
	case '-':
	  result = left_operand - right_operand;
	  break;
	case '*':
	  result = left_operand * right_operand;
	  break;
	case '/':
	  result = left_operand / right_operand;
	  break;
	}
	s.push(result);
      }
    }
    // Assuming if a character is not an operator
    // that it is a number
    else {
      std::string st;
      st.push_back(expression[i]);
      std::istringstream iss(st);
      int num_val = int();
      iss >> num_val;
      s.push(num_val);
    }
  }
  if (s.size() != 1) {
    return 0.0;
  }
  else {
    return s.top();
  }
}
