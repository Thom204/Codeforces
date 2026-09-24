#include <bits/stdc++.h>
#include <sstream>
#define c(d,e) d.find(e) != d.end()

struct Node{
    bool visited;
    string content;

    Node(string c = NULL){
        visited = false;
        content = c;
    }
};

typedef unordered_map<string, unordered_set<string>> dc_aristas;
typedef unordered_map<string, Node> dc_nodos;
typedef vector<vector<bool>> adj_matrix;
using namespace std;

class thin_graph{
    dc_aristas aristas;
    dc_nodos nodos;

    void newArista(string e1, string e2){
        aristas[e1].insert(e2);
        aristas[e2].insert(e1);
    }

    void BFS(const string& start){
        nodos[start].visited = true;
        queue<string> q;
        q.push(start);

        while (!q.empty()) {
            string a = q.front();
            q.pop();
            cout << a << endl;
        
            for (const string& b : aristas[a]) {
                if (!nodos[b].visited) {
                    nodos[b].visited = true;
                    q.push(b);
                }
            }
        }
    }
};


class dense_graph{
    adj_matrix matriz;
    dc_nodos nodos;
};