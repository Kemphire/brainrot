#include <iostream>

class Tree {
  struct Node {
    int data;
    Node *right;
    Node *left;
    Node(int val) {
      data = val;
      right = left = nullptr;
    }
  };
  Node *tree_root;

public:
  Tree(Node *s_root) : tree_root(s_root) {}

  void insert(Node *root, int val) {
    if (!root) {
      Node *to_insert = new Node(val);
      root = to_insert;
      return;
    }

    if (root->data >= val) {
      insert(root->left, val);
    } else {
      insert(root->right, val);
    }
  }

  Node *min_node(Node *root) {
    Node *current = root;
    while (current && current->left) {
      current = current->left;
    }
    return current;
  }

  Node *delete_node(Node *root, int val) {
    if (!root) {
      std::cout << "Tree is empty, there is nothing to remove\n";
      return nullptr;
    }
    if (root->data > val) {
      root->left = delete_node(root->left, val);
    } else if (root->data < val) {
      root->right = delete_node(root->right, val);
    } else {
      if (!root->left && !root->right) {
        delete root;
        return nullptr;
      }

      if (!root->left) {
        Node *temp = root->right;
        delete root;
        return temp;
      }
      if (!root->right) {
        Node *temp = root->left;
        delete root;
        return temp;
      }

      // for case we have tow child in the node
      Node *minimum_node = min_node(root->right);

      root->data = minimum_node->data;

      root->right = delete_node(root->right, minimum_node->data);
    }
    return root;
  }

  Node *replace_x_with_y(Node *root, int x, int y) {
    if (!root) {
      std::cout << "Tree is empty\n";
      return nullptr;
    }

    if (root->data > x) {
      replace_x_with_y(root->left, x, y);
    } else if (root->data < x) {
      replace_x_with_y(root->right, x, y);
    }
  }
};
