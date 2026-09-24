#include<vector>
#include<iostream>

struct Node{
    double key;
    Node *left;
    Node *right;

    Node(double k, Node *l = nullptr, Node *r= nullptr){
        key = k;
        left= l;
        right= r;
    }
};

class BST{
public:
    Node *root;
    
    BST(){
        root= nullptr;
    }
    BST(Node *r){
        root= r;
    }
    BST(double key){
        root= new Node(key);
    }

    void insert(double key){
        root = insertRecursive(root,  key);
    }

    void deleteNode(double key){
        root= deleteRecursive(root, key);
    }

    void yPrint(){
        rec_yPrint(root, 0);
    }

    bool search(double key){
        return !(searchRecursive(root, key) == nullptr);
    }

    bool isComplete(){
        return isRComplete(root);
    }

    int onlyChildren(){
        return recOnlyChildren(root);
    }

    int countLeaves(){
        return countLeavesR(root);
    }

    int depth(){
        return recDepth(root);
    }

    std::vector<double> inOrder(){
        std::vector<double> elem;
        inOrderRecursive(root, &elem);
        return elem;
    }

    std::vector<double> pre_Order(){
        std::vector<double> elem;
        pre_OrderRec(root, &elem);
        return elem;
    }

private:
    Node* insertRecursive(Node *node, double key){
        if (node == nullptr) {
            return new Node(key);
        }if (key < node->key) {
            node->left = insertRecursive(node->left, key);
        }else{
            node->right = insertRecursive(node->right, key);
        }
        return node;
    }

    Node* deleteRecursive(Node *root, double key){
        if(root == nullptr){
            return root;
        }else if(key < root->key){
            root->left = deleteRecursive(root->left, key);
        }else if(key > root->key){
            root->right = deleteRecursive(root->right, key);
        }else{
            if(root->left == nullptr){
                return root->right;
            }else if(root->right==nullptr){
                return root->left;
            }
            root->key= minValNode(root->right)->key;
            root->right= deleteRecursive(root->right, root->key);
        }
        return root;
    }

    Node* searchRecursive(Node *root, double key){
        if (root == nullptr || root->key == key){
            return root;
        }else if(key < root->key){
            return searchRecursive(root->left, key);
        }else{
            return searchRecursive(root->right, key);
        }
    }

    Node* minValNode(Node *node){
        Node *current= node;

        while(current->left != nullptr){
            current= current->left;
        }
        return current;
    }

    int countLeavesR(Node *r){
        if (r == nullptr) return 0;

        if (r->left == nullptr && r->right == nullptr) return 1;

        return countLeavesR(r->left) + countLeavesR(r->right);
    }

    int recDepth(Node *r){
        if(r == nullptr) return 0;

        int lenL= recDepth(r->left);
        int lenR= recDepth(r->right);

        return std::max(lenL, lenR) +1; 
    }

    int recOnlyChildren(Node *r){

        if(r== nullptr) return 0;

        if(r->left == nullptr && r->right == nullptr) return 0;

        else if(r->left == nullptr) return 1 + recOnlyChildren(r->right);

        else if(r->right == nullptr) return 1 + recOnlyChildren(r->left);

        return recOnlyChildren(r->left) + recOnlyChildren(r->right);
    }

    bool isRComplete(Node *r){
        if(r->left == nullptr && r->right == nullptr) return true;

        else if(r->left == nullptr)return false;

        else if(r->right == nullptr)return false;
        
        else return (isRComplete(r->left) && isRComplete(r->right));
    }

    void rec_yPrint(Node *r, int depth, int spacing= 10){
        if(r == nullptr){
            return;
        }

        depth+=spacing;

        rec_yPrint(r->right, depth);

        for(int i=spacing; i<depth; i++) std::cout<<" ";

        std::cout<<r->key<<"\n";

        rec_yPrint(r->left, depth);
    }

    void inOrderRecursive(Node *root, std::vector<double> *v){
        if(root == nullptr){
            return;
        }
        inOrderRecursive(root->left, v);
        v->push_back(root->key);
        inOrderRecursive(root->right, v);
    }

    void pre_OrderRec(Node *r, std::vector<double> *v){
        if(r != nullptr)v->push_back(r->key);
        if(r->left != nullptr) pre_OrderRec(r->left, v);
        if(r->right != nullptr) pre_OrderRec(r->right, v);
    }
};