#include <iostream>

class Queue {
  int *arr;
  int capacity;
  int size;
  int front;
  int rear;

public:
  Queue(int cap) {
    capacity = cap;
    arr = new int[cap];
    size = 0;
    front = -1;
    rear = -1;
  }

  ~Queue() { delete[] arr; }

  bool is_full() { return (rear + 1) % capacity == front; }

  bool is_empty() {
    if (rear == -1)
      return true;
    return false;
  }

  void enqueue(int value) {
    if (is_full()) {
      std::cout << "queue is full, enqueue can't be done\n";
      return;
    }
    if (is_empty()) {
      front = 0;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
    std::cout << "Enqueued: " << value << std::endl;
  }

  int dequeue() {
    if (is_empty()) {
      std::cout << "cannot dequeue from an empty queue\n";
      return -1;
    }
    int dequeued_value = arr[front];
    front = (front + 1) % capacity;
    size--;
    if (size == 0) {
      front = rear = -1;
    }
    return dequeued_value;
  }

  int peek() {
    if (is_empty()) {
      std::cout << "can't dequeue from an empty queue\n";
      return -1;
    }
    return arr[front];
  }

  void display() {
    if (is_empty()) {
      std::cout << "Queue is empty can't display anything\n";
      return;
    }

    for (int i = 0; i < size; i++) {
      std::cout << arr[(i + front) % capacity] << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  Queue cq(5);

  cq.enqueue(10);
  cq.enqueue(20);
  cq.enqueue(30);
  cq.enqueue(40);
  cq.enqueue(50);
  cq.enqueue(60);

  cq.display();

  cq.dequeue();
  cq.dequeue();

  cq.display();

  cq.enqueue(60);
  cq.display();

  return 0;
}
