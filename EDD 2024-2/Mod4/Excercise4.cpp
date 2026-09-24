#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
void splitToVector(string input, vector<int>& arr, int size,char delim){
    int delPos;
    for(int i=0; i<size; i++){
        delPos= input.find_first_of(delim);
        string sub= input.substr(0, delPos);
        input.erase(0, delPos+1);
        arr[i]= stoi(sub);
    }
}


int main(){
    int len, cases, init, end, p;
    string in, inn;
    cin>>len;
    getline(cin>>ws, in);
    cin>>cases;
    vector<int> postes(len+1);
    vector<int> out={};
    splitToVector(in, postes, len+1, ' ');
    sort(postes.begin(), postes.end());

    for(int i=0; i<cases; i++){
        getline(cin>>ws,inn);
        p= inn.find_first_of(' ');
        init= lower_bound(postes.begin(), postes.end(), stoi(inn.substr(0,p)))- postes.begin();
        end= lower_bound(postes.begin(), postes.end(), stoi(inn.substr(p+1, inn.length()-p)))- postes.begin();
        out.push_back(abs(end- init));
    }

    for(int e: out){
        cout<<e<<" kms"<<endl;
    }
    return 0;
}