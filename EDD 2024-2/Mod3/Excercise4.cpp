#include <iostream>
#include <vector>

using namespace std;

int findIn(int n, vector<int>& v){
    for(int i=0; i< v.size(); i++){
        if(v[i]==n){return i;}
    }
    return -1;
}

int main(){
    int in,i, j, k;
    vector<int> players={};
    while(true){
        cin>>in;
        if(in==0){
            break;
        }else{
            i= findIn(in, players);
            j= findIn(in+1, players);
            k= findIn(in-1, players);

            if(i != -1){
                players.erase(players.begin()+i);
            }else if(j != -1){
                players.erase(players.begin()+j);
            }else if(k != -1){
                players.erase(players.begin()+k);
            }else{
                players.push_back(in);
            }
        }
    }
    if(!players.empty()){
        for(int i: players){
            cout<<i<<" ";
        }
    }else{
        cout<<0;
    }
}