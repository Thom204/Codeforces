#include<iostream>
#include<vector>
#include<cmath>
#define pos(s) s.find_first_of(' ')

using namespace std;

void indef_splitToVector(string input, vector<int>& arr, char delim){
    size_t start= 0;
    for(size_t i=0; i<input.length(); i++){
        if(input[i]== delim){
            arr.push_back(stoi(input.substr(start, i-start)));
            start= i+1;
        }
    }
    arr.push_back(stoi(input.substr(start)));
}

vector<int> diviConjunto(int p){
    vector<int> divs={};
    for(int i=1; i<=p; i++){
        if(p%i==0){
            divs.push_back(i);
        }
    }
    return divs;
}

bool primiConjunto(int p, vector<int>& v){
    vector<int> d= diviConjunto(p);
    if(v[0] !=1){
        return false;
    }

    for(int i=0; i<v.size(); i++){
        if(v[i]!= v[i+1] && v[i]==d[0]){
            d.erase(d.begin(), d.begin()+ 1);
            continue;
        }
        if(i==p){break;}
    }
    return d.empty();
}

int main(){
    int cases, len, P;
    string info, in;
    cin>>cases;
    vector<int> vec={};
    vector<bool> out(cases);

    for(int i=0; i<cases; i++){
        getline(cin>>ws, info);
        len= stoi(info.substr(0, pos(info)));
        P= stoi(info.substr(pos(info)));
        getline(cin>>ws, in);
        indef_splitToVector(in, vec, ' ');
        
        out[i]= primiConjunto(P, vec);
        vec.clear();
    }

    for(bool i: out){
        cout<< (i?"Es PrimiConjunto":"No es PrimiConjunto");
        cout<<endl;
    }

    return 0;
}
