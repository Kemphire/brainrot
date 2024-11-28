#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculate_postfix(string expression) {
  stack<int> s;

  for (char ch : expression) {
    if (isdigit(ch)) {
      s.push(ch - '0');
    } else {
      int operand_2 = s.top();
      s.pop();
      int operand_1 = s.top();
      s.pop();

      switch (ch) {
      case '+':
        s.push(operand_1 + operand_2);
        break;
      case '-':
        s.push(operand_1 - operand_2);
        break;
      case '*':
        s.push(operand_2 * operand_1);
        break;
      case '/':
        s.push(operand_1 / operand_2);
        break;
      }
    }
  }

  return s.top();
}

int calculate_prefix(string expression) {
  stack<int> s;

  for (auto it = expression.rbegin(); it != expression.rend(); it++) {
    char ch = *it;
    if (isdigit(ch)) {
      s.push(ch - '0');
    } else {
      int operand_1 = s.top();
      s.pop();
      int operand_2 = s.top();
      s.pop();

      switch (ch) {
      case '+':
        s.push(operand_1 + operand_2);
        break;
      case '-':
        s.push(operand_1 - operand_2);
        break;
      case '*':
        s.push(operand_1 * operand_2);
        break;
      case '/':
        s.push(operand_1 / operand_2);
        break;
      }
    }
  }
  return s.top();
}

int main() {
  string exp = "53+2*";
  cout << calculate_postfix(exp) << endl;
}
