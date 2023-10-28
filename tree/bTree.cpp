#include <iostream>
#include <vector>

const int MAX_KEYS = 3; // 每个节点最大关键字数

struct BTreeNode {
    std::vector<int> keys;      // 存储关键字
    std::vector<BTreeNode*> children;  // 子节点

    BTreeNode() {
        keys.reserve(MAX_KEYS);
        children.reserve(MAX_KEYS + 1);
    }
};

class BTree {
public:
    BTreeNode* root;

    BTree() : root(nullptr) {}

    void insert(int key) {
        if (!root) {
            root = new BTreeNode();
            root->keys.push_back(key);
        } else {
            insertRecursive(root, key);
            if (root->keys.size() > MAX_KEYS) {
                splitRoot();
            }
        }
    }

    bool search(int key) {
        return searchRecursive(root, key);
    }

private:
    void insertRecursive(BTreeNode* node, int key) {
        int i = node->keys.size() - 1;
        while (i >= 0 && key < node->keys[i]) {
            --i;
        }

        if (node->children.empty()) {
            // 如果是叶子节点，直接插入
            node->keys.insert(node->keys.begin() + i + 1, key);
        } else {
            // 否则，递归插入到子节点
            insertRecursive(node->children[i + 1], key);
            if (node->children[i + 1]->keys.size() > MAX_KEYS) {
                splitNode(node, i + 1);
            }
        }
    }

    void splitNode(BTreeNode* parent, int index) {
        BTreeNode* child = parent->children[index];
        BTreeNode* newNode = new BTreeNode();

        parent->keys.insert(parent->keys.begin() + index, child->keys[MAX_KEYS / 2]);

        newNode->keys.insert(newNode->keys.begin(), child->keys.begin() + MAX_KEYS / 2 + 1, child->keys.end());
        child->keys.erase(child->keys.begin() + MAX_KEYS / 2, child->keys.end());

        if (!child->children.empty()) {
            newNode->children.insert(newNode->children.begin(), child->children.begin() + MAX_KEYS / 2 + 1, child->children.end());
            child->children.erase(child->children.begin() + MAX_KEYS / 2 + 1, child->children.end());
        }

        parent->children.insert(parent->children.begin() + index + 1, newNode);
    }

    void splitRoot() {
        BTreeNode* newRoot = new BTreeNode();
        newRoot->children.push_back(root);
        root = newRoot;
        splitNode(newRoot, 0);
    }

    bool searchRecursive(BTreeNode* node, int key) {
        int i = 0;
        while (i < node->keys.size() && key > node->keys[i]) {
            ++i;
        }

        if (i < node->keys.size() && key == node->keys[i]) {
            return true;
        } else if (node->children.empty()) {
            return false;
        } else {
            return searchRecursive(node->children[i], key);
        }
    }
};

int main() {
    BTree btree;

    // 插入一些示例数据
    btree.insert(3);
    btree.insert(7);
    btree.insert(1);
    btree.insert(5);
    btree.insert(9);

    // 搜索示例
    std::cout << "Search 5: " << (btree.search(5) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 8: " << (btree.search(8) ? "Found" : "Not found") << std::endl;

    return 0;
}
