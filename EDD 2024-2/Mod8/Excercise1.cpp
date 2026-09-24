#include "strAVLtree.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int c;
    cin >> c;
    cin.ignore();
    while (c-- > 0) {
        AVLTree avl;
        string line, val;
        getline(cin, line);
        istringstream iss(line);
        while (iss >> val) {
            if (val == "#") break;
            avl.insert(val);
        }
        vector<string> result = avl.posOrder();
        for (const string& num : result) {
            cout << num;
        }
        cout << endl;
    }
    return 0;
}