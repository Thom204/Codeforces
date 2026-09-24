#include <bits/stdc++.h>
#include <sstream>
#define contains(regs, document) regs.find(document) == regs.end()

using namespace std;
typedef unordered_set<int> uSet;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    uSet regs;
    char key;
    int document;
    string input;

    while(true){
        getline(cin>>ws,input);
        stringstream ss(input);

        if(input=="E") break;
        
        ss>>key;
        ss>>document;

        bool b = contains(regs, document);

        if(key=='B' && !b){
            regs.insert(document);
        }else if(key=='D' && b){
            regs.erase(document);
        }else if(key == 'R' && !b){}
    }
}