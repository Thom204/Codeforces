#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;
class Node{
public:
    bool visited;
    int content;
    int dia;

    Node(int c): visited(false), content(c), dia(-1){}

    string getPaulina(){
        return (dia == -1)? "INF" : to_string(dia);
    }
};

typedef unordered_map<int, unordered_set<int>> dc_aristas;
typedef unordered_map<int, Node*> dc_nodos;

class thin_graph{
public:
    dc_aristas aristas;
    dc_nodos nodos;

    void newArista(int e1,int e2){
        aristas[e1].insert(e2);
        aristas[e2].insert(e1);
    }

    void newNode(int e){
        if(!(c(nodos, e))) nodos[e] = new Node(e);
    }

    pair<int, int> spreadGossip(int startPerson) {
        for (auto& p : nodos) {
            p.second->visited = false;
            p.second->dia = -1;
        }

        queue<int> q;
        q.push(startPerson);
        nodos[startPerson]->visited = true;
        nodos[startPerson]->dia = 0;

        unordered_map<int, int> dailyCount;
        int maxDay = -1, maxCount = 0;

        while (!q.empty()) {
            int person = q.front();
            q.pop();
            int day = nodos[person]->dia;

            for (int friendID : aristas[person]) {
                if (!nodos[friendID]->visited) {
                    nodos[friendID]->visited = true;
                    nodos[friendID]->dia = day + 1;
                    q.push(friendID);

                    dailyCount[day + 1]++;
                    if (dailyCount[day + 1] > maxCount) {
                        maxCount = dailyCount[day + 1];
                        maxDay = day + 1;
                    }
                }
            }
        }

        return (maxCount == 0) ? make_pair(0, 0) : make_pair(maxDay, maxCount);
    }

    void reset(){
        for(auto & [id, nodo]: nodos){
            nodo->dia=-1;
        }
    }

};


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int personas, bailarines,turnos, amigo, origen;
    string entrada, prueba;
    char comma;
    cin>>personas;
    thin_graph comunidad;

    for(int i =0; i<personas;  i++){

        getline(cin>>ws, entrada);  
        
        stringstream ss(entrada);
        
        comunidad.newNode(i);

        while(ss>>amigo){
            if(amigo != -1) comunidad.newArista(i, amigo);
        }
    }

    getline(cin>>ws, prueba);
    stringstream ps(prueba+',');

    while (ps>>origen>>comma){
        pair<int,int> resultado = comunidad.spreadGossip(origen);
        
        if(resultado.first==0) cout<<0<<endl;
        else cout<<resultado.first<<" "<<resultado.second<<endl;
    }
}