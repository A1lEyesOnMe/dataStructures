#include <iostream>
#include <queue>

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree
{
private:
    TreeNode<T> *root;

    TreeNode<T> *insert(TreeNode<T> *node, T value)
    {
        if (node == nullptr)
            return new TreeNode<T>(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    TreeNode<T> *findMin(TreeNode<T> *node)
    {
        if (node == nullptr)
            return nullptr;
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    int findHeight(TreeNode<T> *node)
    {
        if (node == nullptr)
            return 0;

        T leftHeight = findHeight(node->left);
        T rightHeight = findHeight(node->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

    bool search(TreeNode<T> *node, T data)
    {
        if (node == nullptr)
            return false;
        else if (node->data == data)
            return true;
        else if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

    void perOrderTraversal(TreeNode<T> *node)
    {
        if (node != nullptr)
        {
            std::cout << node->data << ' ';
            perOrderTraversal(node->left);
            perOrderTraversal(node->right);
        }
    }

    void inOrderTraversal(TreeNode<T> *node)
    {
        if (node != nullptr)
        {

            perOrderTraversal(node->left);
            std::cout << node->data << ' ';
            perOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(TreeNode<T> *node)
    {
        if (node != nullptr)
        {
            perOrderTraversal(node->left);
            perOrderTraversal(node->right);
            std::cout << node->data << ' ';
        }
    }

    bool isBst(TreeNode<T> *node, int min, int max)
    {
        if (node == nullptr)
            return true;
        if (node->data < min || node->data > max)
            return false;

        return isBst(node->left, min, node->data - 1) &&
               isBst(node->right, node->data + 1, max);
    }

    TreeNode<T> *remove(TreeNode<T> *node, T value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = remove(node->left, value);
        else if (value > node->data)
            node->right = remove(node->right, value);
        else
        {
            if (node->left == nullptr)
            {
                TreeNode<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode<T> *temp = node->left;
                delete node;
                return temp;
            }

            TreeNode<T> *temp = findMin(node->right);

            node->data = temp->data;

            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    TreeNode<T> *findNode(TreeNode<T> *node, T value)
    {
        if (node == nullptr || node->data == value)
            return node;

        if (value < node->data)
            return findNode(node->left, value);
        else
            return findNode(node->right, value);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T value)
    {
        root = insert(root, value);
    }

    bool search(T data)
    {
        return search(root, data);
    }

    TreeNode<T> *findMin()
    {
        return findMin(root);
    }

    int findHeight()
    {
        return findHeight(root);
    }

    void levelOrderTraversal()
    {
        if (root == nullptr)
            return;

        std::queue<TreeNode<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode<T> *current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    void preOrderTraversal()
    {
        preOrderTraversal(root);
        std::cout << "\n";
    }

    void inOrderTraversal()
    {
        inOrderTraversal(root);
        std::cout << "\n";
    }

    void postOrderTraversal()
    {
        postOrderTraversal(root);
        std::cout << "\n";
    }

    bool isBst()
    {
        return isBst(root, INT_MIN, INT_MAX);
    }

    T getSuccessor(T value)
    {
        TreeNode<T> *current = findNode(root, value);

        if (current = nullptr)
            return T();

        if (current->right != nullptr)
        {
            current = current->right;
            while (current->right != nullptr)
                current = current->left;
            return current->data;
        }

        TreeNode<T> *succesor{nullptr};
        TreeNode<T> *ancestor{root};

        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                succesor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right
            }
        }
        if (succesor != nullptr)
            return succesor->data;
        else
            return T();
    }
};

int main()
{
    BinarySearchTree<int> bst;

    // Insert some values
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    // Search for values
    if (bst.search(7))
        std::cout << "Found 7\n";
    else
        std::cout << "Not Found 7\n";

    if (bst.search(20))
        std::cout << "Found 20\n";
    else
        std::cout << "Not Found 20\n";

    std::cout << bst.findMin()->data << "\n";
    std::cout << bst.findHeight() << "\n";

    bst.levelOrderTraversal();
    std::cout << "\n";

    return 0;
}
