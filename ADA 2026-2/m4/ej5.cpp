#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Nodo {
    long long frecuencia;
    string etiqueta; // Carácter de la hoja o concatenación de sus hijos.
    char caracter;   // Solo se usa en hojas.
    int izquierdo;
    int derecho;
};

struct Comparar {
    const vector<Nodo>* nodos;

    bool operator()(int a, int b) const {
        const Nodo& x = (*nodos)[a];
        const Nodo& y = (*nodos)[b];
        if (x.frecuencia != y.frecuencia) {
            return x.frecuencia > y.frecuencia;
        }
        return x.etiqueta > y.etiqueta;
    }
};

void imprimirEnOrden(int indice, const vector<Nodo>& nodos,
                     const string& codigo) {
    const Nodo& nodo = nodos[indice];
    if (nodo.izquierdo == -1) {
        cout << nodo.caracter << ' ' << codigo << '\n';
        return;
    }

    imprimirEnOrden(nodo.izquierdo, nodos, codigo + '0');
    imprimirEnOrden(nodo.derecho, nodos, codigo + '1');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int casos;
    cin >> casos;

    for (int caso = 1; caso <= casos; ++caso) {
        int n;
        cin >> n;

        vector<Nodo> nodos;
        nodos.reserve(2 * n - 1);
        priority_queue<int, vector<int>, Comparar> cola(Comparar{&nodos});

        for (int i = 0; i < n; ++i) {
            char caracter;
            long long frecuencia;
            cin >> caracter >> frecuencia;
            nodos.push_back({frecuencia, string(1, caracter), caracter, -1, -1});
            cola.push(static_cast<int>(nodos.size()) - 1);
        }

        while (cola.size() > 1) {
            int izquierdo = cola.top();
            cola.pop();
            int derecho = cola.top();
            cola.pop();

            string etiqueta = nodos[izquierdo].etiqueta +
                              nodos[derecho].etiqueta;
            nodos.push_back({nodos[izquierdo].frecuencia +
                                 nodos[derecho].frecuencia,
                             move(etiqueta), '\0', izquierdo, derecho});
            cola.push(static_cast<int>(nodos.size()) - 1);
        }

        if (caso > 1) cout << '\n';
        cout << "caso " << caso << ":\n";
        imprimirEnOrden(cola.top(), nodos, "");
    }

    return 0;
}
