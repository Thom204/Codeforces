#include <bits/stdc++.h>
#include <sstream>
#define cont(p, h) p.find(h) != p.end()

using namespace std;
typedef unordered_set<int> iSet;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    iSet lFer, lGus, coleccion;
    string com, prop;
    int isbn;

    while(true){
        getline(cin>>ws, com);
        stringstream ss(com);
        ss>>isbn;
        if (isbn==0) break;

        ss>>prop;

        if (prop == "G" ){
            if (cont(lFer, isbn)){
                coleccion.insert(isbn);
                lFer.erase(isbn);   
            }
            else lGus.insert(isbn);

        }else if(prop == "F"){
            if (cont(lGus, isbn)){
                coleccion.insert(isbn);
                lGus.erase(isbn);    
            }

            else lFer.insert(isbn);
        }
    }

    for(int e: coleccion){
        if(cont(lFer, e)) lFer.erase(e);
        if(cont(lGus, e)) lGus.erase(e);

        e%2==0? lFer.insert(e): lGus.insert(e);
    }

    cout<<lFer.size()<<" "<<lGus.size();

    return 0;
}