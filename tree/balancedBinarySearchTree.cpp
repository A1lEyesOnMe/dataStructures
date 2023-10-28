#include <iostream>
#include <algorithm>

template <typename T>
class AVLTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;

        Node(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    // 获取节点的高度
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // 计算节点的平衡因子
    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

    // 更新节点的高度
    void updateHeight(Node* node) {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    // 右旋转
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // 左旋转
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // 插入节点
    Node* insert(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            // Duplicate values are not allowed
            return node;
        }

        // 更新节点的高度
        updateHeight(node);

        // 获取平衡因子
        int balance = balanceFactor(node);

        // 进行平衡维护
        if (balance > 1) {
            // 左子树较高
            if (value < node->left->data) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            // 右子树较高
            if (value > node->right->data) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    // 查找节点并删除
    Node* remove(Node* node, const T& value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // 找到要删除的节点

            if (node->left == nullptr || node->right == nullptr) {
                // 有一个或零个子节点的情况
                Node* temp = (node->left != nullptr) ? node->left : node->right;

                if (temp == nullptr) {
                    // 没有子节点
                    temp = node;
                    node = nullptr;
                } else {
                    // 有一个子节点
                    *node = *temp; // 将子节点的内容复制到当前节点
                }

                delete temp;
            } else {
                // 有两个子节点的情况，找到右子树中的最小节点来替代当前节点
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        // 更新节点的高度
        updateHeight(node);

        // 获取平衡因子
        int balance = balanceFactor(node);

        // 进行平衡维护
        if (balance > 1) {
            if (balanceFactor(node->left) >= 0) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            if (balanceFactor(node->right) <= 0) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    // 查找最小节点
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // 删除整棵树
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}

    // 插入
    void insert(const T& value) {
        root = insert(root, value);
    }

    // 删除
    void remove(const T& value) {
        root = remove(root, value);
    }

    // 清空
    void clear() {
        clear(root);
        root = nullptr;
    }
};

int main() {
    AVLTree<int> avl;
    avl.insert(3);
    avl.insert(2);
    avl.insert(1);
    avl.insert(4);

    avl.remove(2);

    avl.clear();
    

    return 0;
}
