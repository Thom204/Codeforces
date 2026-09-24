#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include "AVLtree.cpp"

using namespace std;

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

        while (avl.getSize() > 1){
            int a = avl.findMin();
            int b = avl.findMax();
            int result = b-a;
            avl.deleteNode(a);
            avl.deleteNode(b);

            if(!avl.search(result)) avl.insert(result);
        }
        cout << avl.findMin();
    }
    return 0;
}