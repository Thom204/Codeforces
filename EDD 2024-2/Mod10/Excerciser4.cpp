#include <bits/stdc++.h>

using namespace std;
typedef map<string,vector<pair<string,string>>> dict;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    set<string> dictionary;
    dict compounds;
    string word;
    
    while (getline(cin>>ws, word) && word != "#") {
        dictionary.insert(word);
    }
    for(string word: dictionary){
        
        int len = word.size();
        for (int i = 1; i < len; ++i) {
            string first = word.substr(0, i);
            string second = word.substr(i);
            
            if (dictionary.count(first) && dictionary.count(second)) {
                compounds[word].push_back({first, second});
            }
        }
    }

    for (const auto& entry : compounds) {
        for (const auto& pair: compounds[entry.first]){
            cout << entry.first << " = " << pair.first << " + " << pair.second <<endl; 
        }
    }
    
    return 0;
}