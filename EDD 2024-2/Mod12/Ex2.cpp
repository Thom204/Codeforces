#include <bits/stdc++.h>
#define nc(N, c) N->children.find(c) == N->children.end()
using namespace std;

class Trie {
    struct Node {
        bool endWord;
        unordered_map<char, Node*> children;
        int count;
        Node() : endWord(false), count(0){}
    };

    Node* root;
    

public:
    Trie() : root(new Node()) {}

    void insert(const string& word) {
        Node* current = root;
        for (char ch : word) {
            if (nc(current, ch)) {
                current->children[ch] = new Node();
            }
            current = current->children[ch];
            current->count++;
        }
        current->endWord = true;
    }

    int count_w_prefix(const string& prefix){
        Node *r =root;
        for(char c :prefix){
            if(nc(r, c)) return 0;
            r = r->children[c];
        }
        return r->count;
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
    int n, m;
    Trie a;
    string word;
    cin>>n;

    for(int _ =0; _<n; _++){        
        cin>>word;
        a.insert(word);
    }

    cin>>m;
    for(int _ =0; _<m; _++){
        cin>>word;
        cout<< a.count_w_prefix(word)<<endl;        
    }
}
