#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;
class Node{
public:
    bool visited;
    int content;
    int numeroPaulina;

    Node(int c): visited(false), content(c), numeroPaulina(-1){}

    string getPaulina(){
        return (numeroPaulina == -1)? "INF" : to_string(numeroPaulina);
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

    void paulina_BFS(){
        nodos[0]->visited = true;
        nodos[0]->numeroPaulina = 0;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int a = q.front();
            q.pop();
        
            for (int b : aristas[a]) {
                if (!nodos[b]->visited) {
                    nodos[b]->visited = true;
                    nodos[b]->numeroPaulina = nodos[a]->numeroPaulina+1;
                    q.push(b);
                }
            }
        }
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int cases, bailarines,turnos, id1, id2;
    char comma;
    string entrada;
    cin>>cases;
    
    for(int i =0; i<cases;  i++){
        thin_graph numero_paulina;
        getline(cin>>ws, entrada);  
        set<int> idx;
        stringstream ss(entrada);
        ss>>bailarines>>comma>>turnos;

        for (int j=0; j<turnos; j++) {
            getline(cin>>ws, entrada);

            stringstream turno(entrada);
            turno>>id1>>id2;
            numero_paulina.newArista(id1, id2);
            numero_paulina.newNode(id1);
            numero_paulina.newNode(id2);
            if(id1!=0) idx.insert(id1);
            if(id2!=0) idx.insert(id2);
        }

        numero_paulina.paulina_BFS();
        cout<<"fiesta "<<i+1<<":"<<endl;

        for(int n: idx){
            cout<<n<<" "<<numero_paulina.nodos[n]->getPaulina()<<endl;
        }
        cout<<endl;

    }
    return 0;
}