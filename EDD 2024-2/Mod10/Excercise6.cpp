#include <bits/stdc++.h>
using namespace std;

#define c(d, v) (find(d.begin(), d.end(), v) != d.end())

bool isPrime(int p) {
    if (p < 2) return false;
    int n = sqrt(p);
    for (int i = 2; i <= n; i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

int golbachPairs(int n, const vector<int> &primos) {
    int contador = 0;
    for (int i : primos) {
        int complemento = n - i;
        if (i > complemento) break; 
        if (c(primos, complemento)) contador++;
    }
    return contador;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int casos, n;
    cin >> casos;

    vector<int> primos;
    for (int i = 2; i <= 10000; i++) {
        if (isPrime(i)) primos.push_back(i);
    }

    while (casos--) {
        cin >> n;
        cout << golbachPairs(n, primos) << endl;
    }

    return 0;
}