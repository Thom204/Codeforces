#include <bits/stdc++.h>
#define nc(N, c) N->children.find(c) == N->children.end()
using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    int count;
    Node() : count(0) {}
};

class Trie {
    Node* root;
public:
    Trie() : root(new Node()) {}

    void insert(const string& word) {
        Node* r = root;
        for (char c : word) {
            if (nc(r, c)) {
                r->children[c] = new Node();
            }
            r = r->children[c];
            r->count++;
        }
    }
    int uniquePrefixLength(const string& word) {
        Node* r = root;
        int length = 0;

        for (char c : word) {
            r = r->children[c];
            length++;
            if (r->count == 1) break;
        }

        return length;
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    while (true) {
        int A;
        cin >> A;
        if (A == 0) break;

        Trie *trie = new Trie();
        vector<string> asteroids(A);

        for (int i = 0; i < A; i++) {
            cin >> asteroids[i];
            trie->insert(asteroids[i]);
        }

        int totalLength = 0;
        for (const string& asteroid : asteroids) {
            totalLength += trie->uniquePrefixLength(asteroid);
        }

        cout << totalLength << endl;
        delete trie;
    }

    return 0;
}
