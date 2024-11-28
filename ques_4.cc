#include <iostream>

#define IF_NULL_RETURN_N(x)                                                    \
  if (!(x))                                                                    \
    return x;

class List {
  struct Node {
    int val;
    Node *front, *back;
    Node(int v) : val(v) { front = back = nullptr; }
  };
  Node *root;

public:
  List(Node *root_s) : root(root_s) {}
  void insert_at_begining(int val) {
    Node *to_insert = new Node(val);
    if (!root) {
      root = to_insert;
      root->front = to_insert;
      root->back = to_insert;
    } else {
      Node *tail = root->back;
      to_insert->front = root;
      to_insert->back = tail;
      tail->front = to_insert;
      root->back = to_insert;
      root = to_insert;
    }
  }

  void insert_at_back(int val) {
    Node *to_insert = new Node(val);
    if (!root) {
      root = to_insert;
      root->front = to_insert;
      root->back = to_insert;
    } else {
      Node *tail = root->back;
      tail->front = to_insert;
      to_insert->front = root;
      to_insert->back = tail;
      root->back = to_insert;
    }
  }

  void remove_at_back() {
    if (!root) {
      std::cout << "List is empty\n";
      return;
    }
    if (root->front == root) {
      delete root;
      root = nullptr;
    } else {
      Node *tail = root->back;
      Node *new_tail = tail->back;
      root->back = new_tail;
      new_tail->front = root;
      delete tail;
    }
  }

  void display() {
    if (!root) {
      std::cout << "List is empty\n";
      return;
    }
    Node *current = root;
    do {
      std::cout << current->val << " ";
      current = current->front;
    } while (current->front != root);
    std::cout << std::endl;
  }

  void insert_x_after_y(Node *x, Node *y) {
    if (!root) {
      std::cout << "List is empty\n";
      return;
    }
    if (root->front == root) {
      if (root == y) {
        root->front = x;
        x->back = root;
        x->front = root;
        root->back = x;
      } else {
        std::cout << "No x in the list\n";
        return;
      }
    } else {
      Node *current = root;
      do {
        current = current->front;
      } while (current != y);
      Node *new_front_of_x = current->front;
      x->back = current;
      current->front = x;
      x->front = new_front_of_x;
    }
  }

  void remove_at_front() {
    if (!root) {
      std::cout << "List is empty\n";
      return;
    }
    if (root == root->front) {
      delete root;
      root = nullptr;
    } else {
      Node *to_remove = root;
      Node *tail = root->back;
      Node *new_front = root->front;

      tail->front = new_front;
      new_front->back = tail;
      root = new_front;
      delete to_remove;
    }
  }

  void remove_x(Node *x) {
    if (!root) {
      return;
    }
    if (root->front == root) {
      if (root == x) {
        delete root;
        root = nullptr;
      } else {
        std::cout << "x not found in the list\n";
        return;
      }
    } else {
      Node *current = root;
      do {
        current = current->front;
      } while (current != x);
      Node *tail = current->back;
      Node *front = current->front;
      tail->front = front;
      front->back = front;
      delete current;
    }
  }

  Node *search(Node *x) {
    IF_NULL_RETURN_N(x)
    Node *current = root;
    do {
      current = current->front;
    } while (current != x);
    return current;
  }

  List *concatenate(Node *new_root, List *other) {
    List *to_return = new List(new_root);
    Node *current = this->root;

    if (current) {
      do {
        to_return->insert_at_back(current->val);
        current = current->front;
      } while (current != this->root);
    }

    current = other->root;
    if (current) {
      do {
        to_return->insert_at_back(current->val);
        current = current->front;
      } while (current != other->root);
    }
    return to_return;
  }
};
