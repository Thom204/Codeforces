#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;
typedef unordered_map<string, string> dict;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    string entrada, Ewok, spanish;
    dict diccionario;

    cin>>n;
    for(int _=0; _<n; _++){
        getline(cin>>ws, entrada);
        stringstream ss(entrada);

        ss>>Ewok>>spanish;

        diccionario[Ewok] = spanish;
    }

    while (getline(cin>>ws, entrada) && entrada != "#"){
        cout<< (c(diccionario, entrada)? diccionario[entrada] : "Entrada no encontrada") <<endl;
    }
    
    return 0;
}