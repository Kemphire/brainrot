#include <iostream>

class CircularQueue {
  struct Node {
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
  };
  Node *rear;
  int size;
  int capacity;

public:
  CircularQueue(int cap) : rear(nullptr), size(0), capacity(cap) {}

  bool is_full() { return size == capacity; }

  bool is_empty() { return size == 0; }

  void enqueue(int val) {
    if (is_full()) {
      std::cout << "Stack Overflow occured\n";
      return;
    }
    Node *new_node = new Node(val);
    if (is_empty()) {
      new_node->next = new_node;
      rear = new_node;
    } else {
      new_node->next = rear->next;
      rear->next = new_node;
      rear = new_node;
    }
    size++;
  }

  int dequeue() {
    if (is_empty()) {
      std::cout << "Stack Underflow\n";
      return -1;
    }

    Node *front = rear->next;
    int value_to_return = front->data;

    if (size == 1) {
      delete front;
      rear = nullptr;
    } else {
      rear->next = front->next;
      delete front;
    }
    size--;
    return value_to_return;
  }

  int peek() {
    if (is_empty()) {
      std::cout << "Stack underflow\n";
      return -1;
    } else {
      return rear->next->data;
    }
  }
};
