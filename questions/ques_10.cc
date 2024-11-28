#include <iostream>

class Dequeue {
  int *arr;
  int capacity;
  int front;
  int rear;
  int size;

public:
  Dequeue(int cap)
      : arr(new int[cap]), capacity(cap), front(-1), rear(-1), size(0) {}

  ~Dequeue() { delete[] arr; }

  bool is_empty() { return size == 0; }
  bool is_full() { return size == capacity; }

  void push_front(int val) {
    if (is_full()) {
      std::cout << "No space in queue\n";
      return;
    }
    if (is_empty()) {
      front = rear = 0;
    } else {
      front = (front - 1 + capacity) % capacity;
    }
    arr[front] = val;
    size++;
  }

  void push_back(int val) {
    if (is_full()) {
      std::cout << "No space in queue\n";
      return;
    }
    if (is_empty()) {
      rear = front = 0;
    } else {
      rear = (rear + 1) % capacity;
    }
    arr[rear] = val;
    size++;
  };

  int pop_front() {
    if (is_empty()) {
      std::cout << "the queue is completely empty\n";
      return -1;
    }

    std::cout << "Popped element: " << arr[front] << std::endl;
    int to_return = arr[front];

    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % capacity;
    }
    size--;
    return to_return;
  }

  int pop_back() {
    if (is_empty()) {
      std::cout << "the queue is completely empty\n";
      return -1;
    }
    int to_return = arr[rear];
    std::cout << "Popped element: " << to_return << std::endl;
    if (front == rear) {
      front = rear = -1;
    } else {
      rear = (rear - 1 + capacity) % capacity;
    }
    return to_return;
  }

  void print() {
    if (is_empty()) {
      std::cout << "Queue is empty\n";
      return;
    }
    int index = front;
    for (int i = 0; i < size; i++) {
      std::cout << arr[index] << " ";
      index = (index + i) % capacity;
    }
    std::cout << "\n";
  }
};
