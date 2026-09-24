/*#include "node.h"

Node::Node(int k){
    key = k;
}

Node::Node(double k){
    key = k;
}

float Node::getKey(){
    return key;
}*/

class Node{
    public:
    double key;
    Node *left;
    Node *right;

    Node(double k, Node *l = nullptr, Node *r= nullptr){
        key = k;
        left= l;
        right= r;
    }
};
