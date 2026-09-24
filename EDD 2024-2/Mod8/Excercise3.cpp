#include <iostream>
#include <vector>
#include <sstream>
#include "AVLtree.cpp"

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while (cin >> n, n != 0) {
        AVLTree avl;
        string line;
        int val;
        cin.ignore();
        getline(cin, line);
        istringstream iss(line);
        while (iss >> val) {
            avl.insert(val);
        }
        cout << avl.getConcentricRing() << endl;
    }
    return 0;
}