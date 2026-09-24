#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;

class Node{
public:
    bool visited;
    bool deforestado;

    Node(bool c): visited(false), deforestado(c){}

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

    void newNode(int id, bool e){
        if(!(c(nodos, id))) nodos[id] = new Node(e);
    }

    pair<int, int> max_component(){
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
    int cases, rows, cols;
    cin >> cases;

    for (int c = 0; c < cases; c++) {
        thin_graph G;
        cin >> rows >> cols;
        vector<string> grid(rows);

        for (int i = 0; i < rows; i++) {
            cin >> grid[i];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'X') {
                    int id = i * cols + j;
                    G.newNode(id, true);

                    if (i > 0 && grid[i - 1][j] == 'X') {
                        int arriba = (i - 1) * cols + j;
                        G.newArista(id, arriba);
                    }
                    
                    if (j > 0 && grid[i][j - 1] == 'X') {
                        int izquierda = i * cols + (j - 1);
                        G.newArista(id, izquierda);
                    }
                }
            }
        }

        pair<int, int> resultado = G.max_component();
        cout << resultado.second << endl;
    }
    return 0;
}