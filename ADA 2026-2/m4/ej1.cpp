#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Nino {
    long long hora;      // hora límite para empezar, múltiplo de 10
    long long pataleta;  // costo si empieza después de esa hora
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int casos;
    cin >> casos;

    while (casos--) {
        int n;
        cin >> n;

        vector<Nino> ninos(n);
        long long pataletaTotal = 0;
        for (Nino& nino : ninos) {
            cin >> nino.hora >> nino.pataleta;
            pataletaTotal += nino.pataleta;
        }

        sort(ninos.begin(), ninos.end(), [](const Nino& a, const Nino& b) {
            if (a.pataleta != b.pataleta) return a.pataleta > b.pataleta;
            return a.hora < b.hora;
        });

        // DSU: encuentra el último turno libre no posterior al límite.
        vector<int> padre(n + 1);
        iota(padre.begin(), padre.end(), 0);
        auto buscar = [&](auto&& self, int x) -> int {
            if (padre[x] == x) return x;
            return padre[x] = self(self, padre[x]);
        };

        long long pataletaEvitada = 0;
        for (const Nino& nino : ninos) {
            long long limite = nino.hora / 10 + 1;
            int turnoMaximo = static_cast<int>(min<long long>(n, limite));
            int turno = buscar(buscar, turnoMaximo);
            if (turno > 0) {
                pataletaEvitada += nino.pataleta;
                padre[turno] = buscar(buscar, turno - 1);
            }
        }

        cout << pataletaTotal - pataletaEvitada << '\n';
    }

    return 0;
}
