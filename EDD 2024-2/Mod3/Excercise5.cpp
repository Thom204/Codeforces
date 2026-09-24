#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string median(int n, vector<int>& v){
    sort(v.begin(), v.end());
    int res;
    if (n % 2 == 0) {
        res= v[n/2 - 1] + v[n/2];
        string out= res%2==0?to_string(res/2):to_string(res)+"/2";
        return out; 
    } else {
        return to_string(v[n / 2]);
    }
}

int main(){
    long in, n;
    int M;
    vector<int> v={};
    vector<string> out={};
    cin>>M;
    while(true){
        cin>>in;
        if(in==0){break;}
        else{
            v.push_back(in);
            n= v.size();
            if(n%M==0){
                out.push_back(median(n, v));
            }
        }
    }
    for(string i: out){
        cout<<i<<endl;
    }
    return 0;
}