#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

class Node {
public:
    long long key;
    Node* left;
    Node* right;
    long long height;
    
    Node(long long k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;
    long long size;

    long long getNodeHeight(Node* node) {
        return node ? node->height : 0;
    }

    long long getNodeBalance(Node* node) {
        return node ? getNodeHeight(node->left) - getNodeHeight(node->right) : 0;
    }

    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* aux = y->left;
        y->left = z;
        z->right = aux;
        
        z->height = 1 + max(getNodeHeight(z->left), getNodeHeight(z->right));
        y->height = 1 + max(getNodeHeight(y->left), getNodeHeight(y->right));
        
        return y;
    }

    Node* rightRotate(Node* z) {
        Node* y = z->left;
        Node* aux = y->right;
        y->right = z;
        z->left = aux;
        
        z->height = 1 + max(getNodeHeight(z->left), getNodeHeight(z->right));
        y->height = 1 + max(getNodeHeight(y->left), getNodeHeight(y->right));
        
        return y;
    }

    Node* insertRecursively(Node* root, long long key) {
        if (!root) {
            size++;
            return new Node(key);
        }
        if (key < root->key)
            root->left = insertRecursively(root->left, key);
        else
            root->right = insertRecursively(root->right, key);
        
        root->height = 1 + max(getNodeHeight(root->left), getNodeHeight(root->right));
        
        int balance = getNodeBalance(root);
        
        if (balance > 1) {
            if (key < root->left->key)
                return rightRotate(root);
            else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        if (balance < -1) {
            if (key > root->right->key)
                return leftRotate(root);
            else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }

    Node* deleteRecursively(Node* root, long long key) {
        if (!root) return root;
        
        if (key < root->key)
            root->left = deleteRecursively(root->left, key);
        else if (key > root->key)
            root->right = deleteRecursively(root->right, key);
        else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            size--;
            Node* temp = getMinNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursively(root->right, temp->key);
        }
        
        root->height = 1 + max(getNodeHeight(root->left), getNodeHeight(root->right));
        int balance = getNodeBalance(root);
        
        if (balance > 1) {
            if (getNodeBalance(root->left) >= 0)
                return rightRotate(root);
            else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        
        if (balance < -1) {
            if (getNodeBalance(root->right) <= 0)
                return leftRotate(root);
            else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }

    Node* getMinNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* getMaxNode(Node* node) {
        while (node->right) node = node->right;
        return node;
    }

    pair<int, int> dfs(Node* node) {
        if (!node) return {0, 0};
        
        auto [leftSize, leftHeight] = dfs(node->left);
        auto [rightSize, rightHeight] = dfs(node->right);
        
        int h = min(leftHeight, rightHeight) + 1;
        int expectedNodes = (1 << h) - 1; 
        
        if (leftSize + rightSize + 1 == expectedNodes)
            return {expectedNodes, h};
        else
            return {max(leftSize, rightSize) + 1, max(leftHeight, rightHeight)};
    }

public:
    AVLTree() : root(nullptr), size(0) {}

    long getSize(){
        return size;
    }

    void insert(long long key) {
        root = insertRecursively(root, key);
    }

    bool search(long long key) {
        Node* temp = root;
        while (temp) {
            if (key == temp->key) return true;
            temp = (key < temp->key) ? temp->left : temp->right;
        }
        return false;
    }

    void deleteNode(long long key) {
        root = deleteRecursively(root, key);
    }

    long long findMin() {
        return root ? getMinNode(root)->key : -1;
    }

    long long findMax() {
        return root ? getMaxNode(root)->key : -1;
    }

    int maxCompleteSubtreeHeight() {
        return dfs(root).second;
    }
};

int main() {
    int c;
    while (true) {
        cin>>c;
        if (c==0) break;

        AVLTree avl;
        string line;
        int val;
        cin.ignore();
        getline(cin, line);
        istringstream iss(line);

        while (iss >> val) {
            avl.insert(val);
        }
        
        cout << avl.maxCompleteSubtreeHeight() <<endl;
        
}}