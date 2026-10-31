#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> actividades(n); // (inicio, fin)
        for (auto& [inicio, fin] : actividades) {
            cin >> inicio >> fin;
        }

        sort(actividades.begin(), actividades.end());

        priority_queue<int, vector<int>, greater<int>> finales;
        int maxPersonas = 0;

        for (const auto& [inicio, fin] : actividades) {
            if (!finales.empty() && finales.top() <= inicio) {
                finales.pop();
            }
            finales.push(fin);
            maxPersonas = max(maxPersonas, static_cast<int>(finales.size()));
        }

        cout << max(0, maxPersonas - 1) << '\n';
    }

    return 0;
}
