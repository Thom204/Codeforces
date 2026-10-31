#include <functional>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        priority_queue<long long, vector<long long>, greater<long long>> numeros;

        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            numeros.push(x);
        }

        long long costoTotal = 0;
        while (numeros.size() > 1) {
            long long suma = numeros.top();
            numeros.pop();
            suma += numeros.top();
            numeros.pop();

            costoTotal += suma;
            numeros.push(suma);
        }

        cout << costoTotal << '\n';
    }

    return 0;
}
