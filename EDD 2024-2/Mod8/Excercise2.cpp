#include "AVLtree.cpp"
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    int c;
    cin >> c;
    cin.ignore();
    while (c-- > 0) {
        AVLTree avl;
        string line;
        int val;
        getline(cin, line);
        istringstream iss(line);

        while (iss >> val) {
            if (val == -1) break;
            avl.insert(val);
        }
        cout << avl.relaxingTree() << endl;
    }
    return 0;
}
