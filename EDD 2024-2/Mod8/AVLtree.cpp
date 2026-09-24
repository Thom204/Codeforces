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

    void inOrderRecursively(Node* root, vector<int>& elements) {
        if (root) {
            inOrderRecursively(root->left, elements);
            elements.push_back(root->key);
            inOrderRecursively(root->right, elements);
        }
    }

    void posOrderRecursively(Node* root, vector<int>& elements) {
        if (root) {
            posOrderRecursively(root->left, elements);
            posOrderRecursively(root->right, elements);
            elements.push_back(root->key);
        }
    }

    int recRelax(Node* r, int maxH, int depth){
        if(!r) return 0;

        if (!r->left && !r->right && depth == maxH) return 1;

        return recRelax(r->left,maxH , depth+1) + recRelax(r->right, maxH, depth+1);
    }

    int getNodeChildrenCount(Node* node) { 
        if (!node->left && !node->right) return 0;
        if (node->left && node->right) return 2;
        return node->left ? -1 : 1;
    }

    void rec_yPrint(Node *r, int depth){
        if(r == nullptr){
            return;
        }
        rec_yPrint(r->right, depth+1);

        for(int i=0; i<depth; i++) std::cout<<"/t";

        std::cout<<r->key<<"\n";

        rec_yPrint(r->left, depth+1);
    }

    Node* getMinNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* getMaxNode(Node* node) {
        while (node->right) node = node->right;
        return node;
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

    int relaxingTree(){
        return recRelax(root, getNodeHeight(root), 1);
    }

    void yPrint(){
        rec_yPrint(root, 0);
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

    string getConcentricRing() {
        if (!root) return "";
        
        //recorrido por capas usando queue
        queue<Node*> q;
        q.push(root);
        vector<string> result;
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            result.push_back(to_string(getNodeChildrenCount(current)));
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        
        return join(result, ".");
    }

    static string join(const vector<string>& elements, const string& delimiter) {
        ostringstream oss;
        for (size_t i = 0; i < elements.size(); i++) {
            if (i > 0) oss << delimiter;
            oss << elements[i];
        }
        return oss.str();
    }

    vector<int> inOrder() {
        vector<int> elements;
        inOrderRecursively(root, elements);
        return elements;
    }

    vector<int> posOrder() {
        vector<int> elements;
        posOrderRecursively(root, elements);
        return elements;
    }
};