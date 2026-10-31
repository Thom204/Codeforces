#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> barcos(n); // (extremo izquierdo, derecho)
        for (auto& [izquierdo, derecho] : barcos) {
            cin >> izquierdo >> derecho;
        }

        sort(barcos.begin(), barcos.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        int disparos = 0;
        int ultimaColumnaDisparada = -1;

        for (const auto& [izquierdo, derecho] : barcos) {
            if (ultimaColumnaDisparada < izquierdo) {
                ultimaColumnaDisparada = derecho;
                ++disparos;
            }
        }

        cout << disparos << '\n';
    }

    return 0;
}
