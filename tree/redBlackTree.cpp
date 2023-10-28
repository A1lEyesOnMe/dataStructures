#include <iostream>

enum Color { RED, BLACK };

template <typename Key, typename Value>
class Node {
public:
    Key key;
    Value value;
    Color color;
    Node *left, *right;

    Node(Key key, Value value, Color color) : key(key), value(value), color(color), left(nullptr), right(nullptr) {}
};

template <typename Key, typename Value>
class RedBlackTree {
private:
    Node<Key, Value>* root;

    bool isRed(Node<Key, Value>* node) const {
        if (node == nullptr) {
            return false;
        }
        return node->color == RED;
    }

    Node<Key, Value>* rotateLeft(Node<Key, Value>* h) {
        Node<Key, Value>* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    Node<Key, Value>* rotateRight(Node<Key, Value>* h) {
        Node<Key, Value>* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    void flipColors(Node<Key, Value>* h) {
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

    Node<Key, Value>* put(Node<Key, Value>* h, Key key, Value value) {
        if (h == nullptr) {
            return new Node<Key, Value>(key, value, RED);
        }

        if (key < h->key) {
            h->left = put(h->left, key, value);
        } else if (key > h->key) {
            h->right = put(h->right, key, value);
        } else {
            h->value = value;
        }

        if (isRed(h->right) && !isRed(h->left)) {
            h = rotateLeft(h);
        }
        if (isRed(h->left) && isRed(h->left->left)) {
            h = rotateRight(h);
        }
        if (isRed(h->left) && isRed(h->right)) {
            flipColors(h);
        }

        return h;
    }

    void inorderTraversal(Node<Key, Value>* node) const {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        std::cout << "(" << node->key << ", " << node->value << ") ";
        inorderTraversal(node->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void put(Key key, Value value) {
        root = put(root, key, value);
        root->color = BLACK;
    }

    void inorderTraversal() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTree<int, std::string> rbTree;

    rbTree.put(10, "A");
    rbTree.put(5, "B");
    rbTree.put(15, "C");
    rbTree.put(3, "D");
    rbTree.put(7, "E");

    std::cout << "Inorder Traversal: ";
    rbTree.inorderTraversal();

    return 0;
}
