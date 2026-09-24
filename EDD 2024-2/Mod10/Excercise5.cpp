#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;

typedef long long ll;
typedef map<ll, ll> dict;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    dict candidatos;
    map<ll, ll> votos_por_votante;
    set<ll> votantes_invalidos;
    
    ll votante, candidato;
    string word;
    
    while (getline(cin >> ws, word) && word != "0 0") {
        stringstream ss(word);
        ss >> votante >> candidato;
        
        if (votos_por_votante.count(votante)) {
            votantes_invalidos.insert(votante);
        }
        votos_por_votante[votante] = candidato;
    }
    
    for (const auto& [votante, candidato] : votos_por_votante) {
        if (!(c(votantes_invalidos, votante))) {
            candidatos[candidato]++;
        }
    }

    vector<pair<ll, ll>> sorted_candidatos(candidatos.begin(), candidatos.end());
    sort(sorted_candidatos.begin(), sorted_candidatos.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return (a.second > b.second) || (a.second == b.second && a.first > b.first);
    });


    for (const auto& [id, votos] : sorted_candidatos) {
        cout << id << " " << votos << "\n";
    }
    
    return 0;
}