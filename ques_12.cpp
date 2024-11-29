#include <cmath>
#include <iostream>
#include <queue>

class Tree {
  struct Node {
    int data;
    Node *right;
    Node *left;
    int height;
    Node(int val) {
      data = val;
      height = 0;
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
    root->height = height(root);

    int balance = get_balance_factor(root);

    if (balance > 1 && val < root->left->data) {
      return right_rotation(root);
    }
    if (balance < -1 && val > root->left->data) {
      return left_rotation(root);
    }

    if (balance > 1 && val > root->left->data) {
      return left_right(root);
    }

    if (balance < -1 && val < root->left->data) {
      return right_left(root);
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

      // For the case where the node has two children
      Node *minimum_node = min_node(root->right);

      root->data = minimum_node->data;

      root->right = delete_node(root->right, minimum_node->data);
    }
    root->height = std::max(height(root->left), height(root->right)) + 1;

    // Get balance factor
    int balance = get_balance_factor(root);

    // Balance the tree if needed
    if (balance > 1 && get_balance_factor(root->left) >= 0)
      return right_rotation(root);

    if (balance > 1 && get_balance_factor(root->left) < 0) {
      root->left = left_rotation(root->left);
      return right_rotation(root);
    }

    if (balance < -1 && get_balance_factor(root->right) <= 0)
      return left_rotation(root);

    if (balance < -1 && get_balance_factor(root->right) > 0) {
      root->right = right_rotation(root->right);
      return left_rotation(root);
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

    root = rebalance_from_node(root, x_node,y);
    return root;
  }

  Node *rebalance_from_node(Node *root, Node *node,int value) {
    int value_to_delete = node->data;

    root = delete_node(root,value_to_delete);
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
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    std::cout << root->data << " ";
  }

  void inorder_traversal(Node *root) {
    if (!root) {
      return;
    }
    inorder_traversal(root->left);
    std::cout << root->data << " ";
    inorder_traversal(root->right);
  }

  void bfs_traversal() {
    if (!tree_root) {
      std::cout << "Our tree is empty\n";
      return;
    }
    std::queue<Node *> q;
    q.push(tree_root);

    while (!q.empty()) {
      Node *current = q.front();
      q.pop();

      std::cout << current->data << " ";
      if (current->left)
        q.push(current->left);
      if (current->right)
        q.push(current->right);
    }
    std::cout << std::endl;
  }

  int height(Node *root) {
    if (!root) {
      return -1;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    return std::max(left_height, right_height) + 1;
  }

  Node *left_rotation(Node *x) {
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = height(x);
    y->height = height(y);

    return y;
  }

  Node *right_rotation(Node *x) {
    Node *y = x->left;
    Node *t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = height(x);
    y->height = height(y);
    return y;
  }

  Node *left_right(Node *x) {
    x->left = left_rotation(x->left);
    return right_rotation(x);
  }

  Node *right_left(Node *x) {
    x->right = right_rotation(x->right);
    return left_rotation(x);
  }

  int get_balance_factor(Node *x) {
    return x ? height(x->left) - height(x->right) : 0;
  }
};
