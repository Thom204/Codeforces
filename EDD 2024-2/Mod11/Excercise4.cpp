#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;

class Node{
public:
    int content;
    int color;

    Node(int c): content(c), color(-1) {}

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

    bool bi_BFS(){
        for(auto &[i, _]: nodos){
            if(nodos[i]->color == -1){
                nodos[i]->color = 1;

                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int a = q.front();
                    q.pop();
                
                    for (int b : aristas[a]) {
                        if (nodos[b]->color == -1) {
                            nodos[b]->color = 1 - nodos[a]->color;
                            q.push(b);
                        } else if(nodos[b]->color == nodos[a]->color) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }


};


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int cases, vertices, aristas, v1, v2;
    char comma;
    string entrada;
    cin>>cases;
    
    for(int i =0; i<cases;  i++){
        thin_graph G;
        getline(cin>>ws, entrada);
        stringstream dims(entrada);
        dims>>vertices>>aristas;

        for (int j=1; j<=vertices; j++) G.newNode(j);

        for (int _=0; _<aristas; _++){
            getline(cin>>ws,entrada);
            stringstream ss(entrada);
            ss>>v1>>comma>>v2;
            G.newArista(v1,v2);
        }

        cout<<(G.bi_BFS()?"bipartito":"no bipartito")<<endl;
    }
    return 0;
}