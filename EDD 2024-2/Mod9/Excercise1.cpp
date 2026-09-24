#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    unordered_set<long long> conj;
    unordered_set<long long> vane;
    unordered_set<long long> pipe;
    string input="";
    while(true){
        char iden;
        long long pokeid;

        getline(cin>>ws, input);
        stringstream ss(input);

        ss>>iden;
        if(iden== '#') break;
        ss>>pokeid;
        conj.insert(pokeid);

        (iden == 'V') ? vane.insert(pokeid) : pipe.insert(pokeid);
    }
    cout << pipe.size() <<" "<< vane.size() <<" "<<conj.size();
    return 0;
}