#include "node.h"

class BST{
    public:
        Node *root;

        BST(Node *n);
        BST(double key);
        
        void insert(Node *n);
        void insert(double key);

        void insertRecursive(Node *root, Node *n);

        void search(double key);

        void searchRecursive(Node *root, double key)

        
};