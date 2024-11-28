#include <iostream>

template <class T> struct StackNode {
  T data;
  StackNode *next;

  StackNode(T data) {
    this->data = data;
    next = nullptr;
  };
};

template <typename T> class Stack {
  StackNode<T> *top;

public:
  Stack() : top(nullptr) {}

  void push(T data) {
    StackNode<T> *new_node = new StackNode<T>(data);
    new_node->next = top;
    top = new_node;
  }

  T pop() {
    if (!top) {
      std::cout << "Empty stack\n";
      return T();
    }
    StackNode<T> *new_top = top->next;
    StackNode<T> *to_remove = top;
    T poped = top->data;
    top = new_top;
    delete to_remove;
    return poped;
  }

  T peek() {
    if (top == nullptr) {
      std::cout << "Stack Underflow\n";
      return T();
    }
    return top->data;
  }

  bool is_empty() { return top == nullptr; }
};

int main() {
  Stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);

  std::cout << "Top element is: " << s.peek() << "\n";
  std::cout << "Popped element is: " << s.pop() << "\n";
  std::cout << "Top element after pop is: " << s.peek() << "\n";
  std::cout << "Stack is empty: " << (s.is_empty() ? "Yes" : "No") << "\n";

  return 0;
}
