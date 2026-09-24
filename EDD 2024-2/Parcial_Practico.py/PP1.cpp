#include<vector>
#include<sstream>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string comm;
    int prestigio;
    string input;
    vector<int> v={};
    make_heap(v.begin(), v.end());

    while(true){ 
        getline(cin>>ws, input);
        istringstream str(input);
        str>>comm;

        if(comm == "fin") break;
        else if(comm == "salida"){
            if(!v.empty()){
                pop_heap(v.begin(), v.end());
                v.pop_back();
                cout<<"hasta pronto"<<endl;
            }
        }else if(comm == "ingresa"){
            str >> prestigio;
            if(v.empty() || prestigio >= ceil((float)v[0])/2){
                v.push_back(prestigio);
                push_heap(v.begin(), v.end());
                cout<<"adelante"<<endl;
            }else{
                cout<<"denegado"<<endl;
            }
        }
    }
}