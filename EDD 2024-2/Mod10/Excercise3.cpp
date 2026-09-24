#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;
typedef unordered_map<int, int> dict;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int M, n;
    string entrada, opt;
    unordered_set<int> ganadores;
    dict jugados;
    bool noGanador = true;

    cin>>M;

    while (getline(cin>>ws, entrada) && entrada != "end"){
        stringstream ss(entrada);

        ss>>opt>>n;

        if(opt=="sms"){
            if(c(ganadores, n)){
                c(jugados,n)? jugados[n]++: jugados[n]=1;
                noGanador = false;

                cout<<n<<" "<<(int)(M/(ganadores.size() * jugados[n]))<<endl;

            }else{
                c(jugados,n)? jugados[n]++: jugados[n]=1;               
            }
        }
        if(opt=="winner"){
            ganadores.insert(n);
        }

    }
    if(noGanador) cout<<0;

    return 0;
}