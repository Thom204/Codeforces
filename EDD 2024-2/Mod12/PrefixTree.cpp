#include <bits/stdc++.h>

using namespace std;

class Trie {
    struct Node {
        bool endWord;
        unordered_map<char, Node*> children;
        Node() : endWord(false) {}
    };

    Node* root;
    int count;

public:
    Trie() : root(new Node()), count(0) {}

    void insert(const string& word) {
        Node* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new Node();
            }
            current = current->children[ch];
        }
        if (!current->endWord) {
            current->endWord = true;
            count++;
        }
    }

    bool startsWith(const string& prefix) {
        Node* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) return false;
            current = current->children[ch];
        }
        return !current->children.empty();
    }

    ~Trie() {
        function<void(Node*)> clear = [&](Node* node) {
            for (auto& [_, child] : node->children) {
                clear(child);
            }
            delete node;
        };
        clear(root);
    }
    
};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    while (true) {
        Trie *trie =new Trie();
        vector<string> words;
        bool X = false;

        int C;
        cin >> C;
        if (C == 0) break;

        for (int i = 0; i < C; i++) {
            string ADN;
            cin >> ADN;
            trie->insert(ADN);
            words.push_back(ADN);
        }

        for (const string& word : words) {
            if (trie->startsWith(word)) {
                X = true;
                break;
            }
        }

        cout << (X ? "FALSE" : "TRUE") << endl;
        delete trie;
    }

    return 0;
}
