#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

using int128 = __int128;

void printInt128(int128 n) {
    if (n == 0) {
        cout << "0";
        return;
    }
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

class Node {
public:
    int128 key;
    Node* left;
    Node* right;
    int height;
    
    Node(int128 k) : key(k), left(nullptr), right(nullptr), height(1) {}
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

    Node* insertRecursively(Node* root, int128 key) {
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

    void rec_yPrint(Node *r, int depth){
        if(r == nullptr){
            return;
        }
        rec_yPrint(r->right, depth+1);
        for(int i=0; i<depth; i++) cout << "\t";
        printInt128(r->key);
        cout << "\n";
        rec_yPrint(r->left, depth+1);
    }

public:
    AVLTree() : root(nullptr), size(0) {}

    void insert(int128 key) {
        root = insertRecursively(root, key);
    }

    void yPrint(){
        rec_yPrint(root, 0);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    for(int _ = 0; _ < n; _++) {
        AVLTree avl;
        int order;
        cin >> order;
        int128 f1 = 1, f2 = 1, F;
        
        avl.insert(f1);
        for(int i = 0; i < order - 1; i++) {
            F = f1 + f2;
            avl.insert(F);
            f1 = f2;
            f2 = F;
        }
        
        avl.yPrint();
        cout << endl;
    }
    return 0;
}