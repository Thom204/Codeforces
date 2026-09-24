#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node {
public:
    string key;
    Node* left;
    Node* right;
    int height;
    
    Node(string k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;
    int size;

    int getNodeHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getNodeBalance(Node* node) {
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

    Node* insertRecursively(Node* root, string key) {
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

    void posOrderRecursively(Node* root, vector<string>& elements) {
        if (root) {
            posOrderRecursively(root->left, elements);
            posOrderRecursively(root->right, elements);
            elements.push_back(root->key);
        }
    }

public:
    AVLTree() : root(nullptr), size(0) {}

    void insert(string key) {
        if (!search(key))
            root = insertRecursively(root, key);
    }

    bool search(string key) {
        Node* temp = root;
        while (temp) {
            if (key == temp->key) return true;
            temp = (key < temp->key) ? temp->left : temp->right;
        }
        return false;
    }

    vector<string> posOrder() {
        vector<string> elements;
        posOrderRecursively(root, elements);
        return elements;
    }
};