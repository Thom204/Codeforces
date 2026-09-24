#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;
class Node{
public:
    bool visited;
    int content;

    Node(int c): visited(false), content(c) {}

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

    pair<int, int> subgraph_BFS(){
        int max= 0;
        int cantidad = 0;

        for(auto &[i, _]: nodos){
            if(!(nodos[i]->visited)){
                nodos[i]->visited = true;
                int elements = 1;
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int a = q.front();
                    q.pop();
                
                    for (int b : aristas[a]) {
                        if (!nodos[b]->visited) {
                            elements++;
                            nodos[b]->visited = true;
                            q.push(b);
                        }
                    }
                }
                if(elements > max) max = elements;
                cantidad++;
            }
        }
        return make_pair(cantidad, max);
    }


};


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int cases,registros, id1, id2;
    char comma;
    string entrada;
    cin>>cases;
    
    for(int i =0; i<cases;  i++){
        thin_graph comunidad;
        cin>>registros;

        for (int j=0; j<registros; j++) {
            getline(cin>>ws, entrada);

            stringstream ss(entrada);
            ss>>id1>>id2;
            comunidad.newArista(id1, id2);
            comunidad.newNode(id1);
            comunidad.newNode(id2);
        }

        pair<int,int> res=comunidad.subgraph_BFS();
        cout<<res.first<<" "<<res.second<<endl;

    }
    return 0;
}