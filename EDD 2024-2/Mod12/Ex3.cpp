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

    string maxPrefix(int T) {
        Node* r = root;
        string maxPrefix = "";

        while (r->children.size() == 1) { // Mientras solo tenga un hijo
            auto [j, node] = *(r->children.begin()); // Obtener el único hijo

            if (node->count != T) break; // Si su count no es T, terminamos

            maxPrefix += j; // Agregamos el caracter al prefijo
            r = node; // Movemos el puntero al siguiente nodo
        }

        return maxPrefix.empty() ? "-" : maxPrefix;
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
    int n;
    string word;
    cin>>n;

    while(n !=0 ){
        Trie *a = new Trie();
        for(int _=0; _<n;_++){
            cin>>word;
            a->insert(word);
        }
        cout<<a->maxPrefix(n)<<endl;
        cin>>n;
        delete a;
    }
}
