#include <iostream>

class List {
  struct Node {
    int val;
    Node *left, *right;
    Node(int v) {
      val = v;
      left = nullptr;
      right = nullptr;
    }
  };
  Node *root;

public:
  List(Node *root) : root(root) {}

  void insert_at_x(int val) {
    Node *to_insert = new Node(val);
    if (!root) {
      root = to_insert;
      return;
    } else {
      to_insert->right = root;
      root->left = to_insert;
      root = to_insert;
    }
  }

  void insert_at_i(int i, int val) {
    if (i < 0) {
      std::cout << "Out of range\n";
      return;
    }
    Node *to_insert = new Node(val);
    if (i == 0) {
      to_insert->right = root;
      if (root)
        root->left = to_insert;
      root = to_insert;
      return;
    }
    if (!root) {
      std::cout << "List is empty\n";
      return;
    }
    Node *current = root;
    for (int j = 0; j < i - 1; j++) {
      current = current->right;
    }
    if (!current) {
      std::cout << "Out of range\n";
      return;
    }
    Node *front = current->right;
    current->right = to_insert;
    if (front)
      front->left = to_insert;
    to_insert->left = current;
    front->left = to_insert;
  }

  void insert_at_end(Node *x) {
    if (!root) {
      root = x;
      return;
    }
    Node *current = root;
    do {
      current = current->right;
    } while (current->right);
    current->right = x;
    x->left = current;
  }

  void remove_from_begining() {
    if (!root) {
      std::cout << "List is empty\n";
      return;
    }
    Node *new_root = root->right;
    if (new_root) {
      new_root->left = nullptr;
    }
    delete root;
    root = new_root;
  }

  void remove_from_i(int i) {
    if (!root) {
      std::cout << "List is empty\n";
      return;
    }
    if (i == 0) {
      this->remove_from_begining();
      return;
    }
    if (i < 0) {
      std::cout << "Out of range\n";
      return;
    } else {
      Node *current = root;
      for (int j = 0; j < i - 1 && current; j++) {
        current = current->right;
      }
      if (!current) {
        std::cout << "Out of range\n";
        return;
      }
      Node *to_remove = current->right;
      current->right = to_remove->right;
      if (to_remove->right)
        to_remove->right->left = current;
      delete to_remove;
    }
  }

  void remove_from_end() {
    if (!root) {
      return;
    }
    if (!root->right) {
      delete root;
      root = nullptr;
      return;
    }
    Node *current = root;
    do {
      current = current->right;
    } while (current->right);
    Node *previous = current->left;
    previous->right = nullptr;
    delete current;
  }

  Node *search(Node *x) {
    if (!root) {
      return root;
    }
    Node *current = root;
    while (current->right) {
      if (current == x)
        return current;
      current = current->right;
    }
    return nullptr;
  }

  List *concatenate(Node *root_other, List *other) {
    List *new_list = new List(root_other);

    Node *current = this->root;
    if (current) {
      do {
        new_list->insert_at_end(current);
        current = current->right;
      } while (current->right);
    }
    current = other->root;

    if (current) {
      do {
        new_list->insert_at_end(current);
        current = current->right;
      } while (current->right);
    }

    return new_list;
  }
};
