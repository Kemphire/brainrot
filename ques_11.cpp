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

  Node *insert(Node *root, int val) {
    if (!root) {
      Node *to_insert = new Node(val);
      return to_insert;
    }

    if (root->data >= val) {
      root->left = insert(root->left, val);
    } else {
      root->right = insert(root->right, val);
    }
    return root;
  }

  Node *find_node(Node *root, int val) {
    Node *current = root;
    while (current != nullptr && current->data != val) {
      current = (val > current->data) ? current->right : current->left;
    }
    if (!current) {
      std::cout << val << " not in tree\n";
      return nullptr;
    }
    return current;
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
      std::cout << "Value is not present\n";
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

    Node *x_node = find_node(root, x);
    if (!x_node) {
      std::cout << "X is not in the list\n";
      return root;
    }

    // root = delete_node(root, x_node->data);
    // root = insert(root, y);

    root = rebalance_from_node(root, x_node);
    return root;
  }

  Node *rebalance_from_node(Node *root, Node *node) {
    int value = node->data;

    root = delete_node(root, value);
    root = insert(root, value);

    return root;
  }

  void preorder_traversal(Node *root) {
    if (!root) {
      return;
    }
    std::cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }
  void postorder_traversal(Node *root) {
    if (!root) {
      return;
    }
    std::cout << root->left->data << " ";
    preorder_traversal(root->right->left);
    preorder_traversal(root);
  }

  void inorder_traversal(Node *root) {
    if (!root) {
      return;
    }
    std::cout << root->left->data << " ";
    preorder_traversal(root);
    preorder_traversal(root->right);
  }
};
