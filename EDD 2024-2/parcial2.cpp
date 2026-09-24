#include <bits/stdc++.h>
#include <sstream>
#define nc(d,v) d.find(v) == d.end()
#define c(d,v) d.find(v) != d.end()

using namespace std;

typedef unordered_map<int, int> dict;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    dict carrera;
    unordered_set<int> primer;
    string word;
    int jugador, avance, pos, max;
    max=0;
    
    
    while (getline(cin >> ws, word) && word != "0") {
        stringstream ss(word);
        if(word == "C.AZUL"){
            if(primer.size() != 1) cout<<"SIN OBJETIVO"<<endl;
            else{
                for(int i: primer) cout<<i<<endl;
            }
        }else{
            ss >> jugador >> avance;
            if(nc(carrera, jugador)) carrera[jugador] = 0;

            carrera[jugador]+=avance;
            pos = carrera[jugador];

            if(pos >= max && pos!=0){ 
                if(pos > max) primer.clear();
                max = pos;
                primer.insert(jugador);
            }
        }
    }
    return 0;
}