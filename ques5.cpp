#include <iostream>

template <class T> class Stack {
  T *arr;
  int capacity;
  int top;

public:
  Stack(int capacity) : arr(new T[capacity]), top(-1), capacity(capacity) {}

  bool push(T *val) {
    if (top >= capacity - 1) {
      std::cout << "Stack is full can't stack new elements\n";
      return false;
    }
    arr[++top] = *(val);
    return true;
  }

  T peek() {
    if (top < 0) {
      std::cout << "Stack is empty\n";
      return nullptr;
    }
    return arr[top];
  }

  T pop() {
    if (top < 0) {
      std::cout << "Stack is empty\n";
      return nullptr;
    }
    return arr[top--];
  }

  bool is_empty() { return top < 0;
  }

  bool is_full() {
    return top >= capacity - 1;
  }
};
