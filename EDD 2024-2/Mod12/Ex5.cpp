#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    int count = 0;
    bool endWord = false;
};

class Trie {
    Node* root;

public:
    Trie() : root(new Node()) {}

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                node->children[ch] = new Node();
            node = node->children[ch];
            node->count++;
        }
        node->endWord = true;
    }

    void remove(const string& word) {
        Node* node = root;
        stack<Node*> nodes;
        
        for (char ch : word) {
            nodes.push(node);
            node = node->children[ch];
            node->count--;
        }
        node->endWord = false;

        while (!nodes.empty()) {
            Node* parent = nodes.top();
            nodes.pop();
            char ch = word[nodes.size()];
            if (parent->children[ch]->count == 0) {
                delete parent->children[ch];
                parent->children.erase(ch);
            } else {
                break;
            }
        }
    }

    bool h_depth_words(int k, int h) {
        Node* node = root;
        queue<Node*> q;
        int depth = 0;
        
        q.push(node);
        while (!q.empty() && depth<h) {
            int z =q.size();
            while(z--) {
                node = q.front();
                q.pop();
                for(auto& [_, child]: node->children){
                    q.push(child);
                }
            }
            depth++;
        }

        while(!q.empty()){
            node = q.front();
            if(node->count >=k) return true;
            q.pop();
        }

        return false;
    }
};

int main() {
    Trie trie;
    int P;
    cin >> P;

    while (P--) {
        int op;
        string s;
        cin >> op;
        switch(op){
            case 1:
                cin >> s;
                trie.insert(s);
                break;
            case 2:
                cin >> s;
                trie.remove(s);
                break;
            case 3:
                int k, h;
                cin >> k >> h;
                cout << (trie.h_depth_words(k, h) ? "SI" : "NO") << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
