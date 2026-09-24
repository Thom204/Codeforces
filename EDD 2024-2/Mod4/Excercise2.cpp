#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#define content(v) v.begin(), v.end()

using namespace std;

void indef_splitToVector(string input, vector<int>& arr, char delim){
    int start= 0;
    for(int i=0; i<input.length(); i++){
        if(input[i]== delim){
            arr.push_back(stoi(input.substr(start, i-start)));
            start= i+1;
        }
    }
    arr.push_back(stoi(input.substr(start)));
}

vector<int> Scount(vector<int>& v){
    int last= v[0];
    vector<int> out={1};
    vector<int> elem={last};

    for(int i=1; i<v.size(); i++){
        if(v[i]== last){
            out.back()+=1;
        }else{
            out.push_back(1);
            last=v[i];
        }
    }
    return out;
}

int main(){
    int cases;
    string in, output;
    vector<int> N= {};
    vector<int> out{};
    cin>>cases;

    for (int i=0; i<cases; i++){
        getline(cin>>ws,in);
        indef_splitToVector(in, N, ' ');

        out= Scount(N);

        for(int i: out){
            output.append(to_string(i)+' ');
        }
        if(i!=cases)output.append("\n");
        N.clear();
    }

    cout<<output;
    return 0;
}