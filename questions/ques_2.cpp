#include <iostream>

class List {
  struct Node {
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
  };
  Node *root;

public:
  List(Node *s_root) : root(s_root) {}
  void remove_from_begining() {
    if (!root) {
      return;
    }
    Node *to_remove = root;
    root = root->next;
    delete to_remove;
  }
  void insert_at_begining(int val) {
    Node *to_insert = new Node(val);
    if (!root) {
      root = to_insert;
      return;
    }
    to_insert->next = root;
    root = to_insert;
  }

  void insert_at_i(int i, int val) {
    if (i == 0) {
      Node *to_insert = new Node(val);
      to_insert->next = root;
      root = to_insert;
      return;
    }
    if (i < 0) {
      std::cout << "Out of range\n";
      return;
    }
    Node *current = root;
    for (int j = 0; j < i - 1 && current; j++) {
      current = current->next;
    }
    if (!current) {
      std::cout << "Out of range\n";
      return;
    }
    Node *to_insert = new Node(val);

    to_insert->next = current->next;
    current->next = to_insert;
  }

  void remove_at_i(int i) {
    if (i == 0) {
      Node *new_root = root->next;
      delete root;
      root = new_root;
    }

    if (i < 0) {
      std::cout << "Out of range\n";
      return;
    }
    Node *current = root;
    for (int j = 0; j < i - 1 && current; j++) {
      current = current->next;
    }
    Node *to_remove = current->next;
    current->next = current->next->next;
    delete to_remove;
  }

  Node *search(int val) {
    if (!root)
      return root;
    Node *current = root;
    for (; current;) {
      if (current->val == val) {
        return current;
      }
      current = current->next;
    }
    return current;
  }

  List *concatenate(List *other) {
    if (!this->root) {
      this->root = other->root;
      return this;
    }
    if (!other->root) {
      return this;
    }
    Node *current = this->root;
    while (current->next) {
      current = current->next;
    }
    current->next = other->root;
    return this;
  }
};
