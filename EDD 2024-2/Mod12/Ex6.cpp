#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    int count = 0;
    bool endWord = false;
    int frequency = 0;
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
        }
        node->endWord = true;
        node->frequency++;
    }

    void collectWords(Node* node, const string& prefix, vector<pair<string, int>>& words) {
        if (node->endWord)
            words.emplace_back(prefix, node->frequency);
        for (auto& [ch, child] : node->children) {
            collectWords(child, prefix + ch, words);
        }
    }

    vector<pair<string, int>> searchPrefix(const string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->children.count(ch))
                return {};
            node = node->children[ch];
        }
        vector<pair<string, int>> words;
        collectWords(node, prefix, words);
        return words;
    }
};

vector<string> splitTextIntoWords(const string& text) {
    vector<string> words;
    string current_word;
    for (char ch : text) {
        if (isalpha(ch)) {
            current_word += tolower(ch);
        } else {
            if (!current_word.empty()) {
                words.push_back(current_word);
                current_word.clear();
            }
        }
    }
    if (!current_word.empty()) {
        words.push_back(current_word);
    }
    return words;
}

int main() {
    int L;
    cin >> L;
    cin.ignore();
    string text, line;
    for (int i = 0; i < L; i++) {
        getline(cin, line);
        text += line + " ";
    }
    
    vector<string> words = splitTextIntoWords(text);
    Trie trie;
    for (const string& word : words) {
        trie.insert(word);
    }
    
    int C;
    cin >> C;
    cin.ignore();
    for (int i = 0; i < C; i++) {
        string prefix;
        getline(cin, prefix);
        transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
        
        vector<pair<string, int>> matching_words = trie.searchPrefix(prefix);
        sort(matching_words.begin(), matching_words.end(), [](const auto& a, const auto& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        
        if (!matching_words.empty()) {
            for (const auto& [word, _] : matching_words) {
                cout << word << " ";
            }
            cout << "\n";
        } else {
            cout << "-\n";
        }
    }
    
    return 0;
}
