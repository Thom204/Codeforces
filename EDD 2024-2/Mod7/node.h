class Node {
    public:
        double key;
        Node *left;
        Node *rigth;
        Node(double key, Node *l= nullptr, Node *r= nullptr);
};