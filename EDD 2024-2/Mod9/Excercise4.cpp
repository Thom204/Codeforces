#include <bits/stdc++.h>
#include <sstream>

using namespace std;
typedef unordered_set<int> iSet;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    iSet poblacion;
    string com, key;
    int n1, n2, n3;
    int inip;
    cin>>inip;

    for(int i=1; i<=inip; i++) poblacion.insert(i);

    while(true){
        getline(cin>>ws, com);
        stringstream ss(com);

        if (com=="#") break;

        ss>>key;

        if (key == "new"){
            ss>>n1;
            ss>>n2;
            n3= n1+n2;

            while(poblacion.find(n3) != poblacion.end()) n3++;

            poblacion.insert(n3);
        }else if(key == "search"){
            ss>>n1;
            cout<<((poblacion.find(n1) == poblacion.end())?"no existe":"existe") <<endl;
        }
    }

    return 0;
}