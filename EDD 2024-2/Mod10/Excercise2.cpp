#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<int, bool> hmap;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, t, in;
    cin >> n >> t;

    vector<int> A(n);

    for (int i = 0; i < n; i++) cin >> A[i];

    set<vector<int>> ternas;

    for (int i = 0; i < n; i++) {
        hmap hash_map;
        for (int j = i + 1; j < n; j++) {
            int complemento = t - A[i] - A[j];

            if (hash_map.count(complemento)) {
                vector<int> terna = {A[i], A[j], complemento};
                sort(terna.begin(), terna.end());
                ternas.insert(terna);
            }

            hash_map[A[j]] = true;
        }
    }
    if (ternas.empty()) cout<<"No hay trillizas"<<endl;
    
    else{
        for (const vector<int> &terna : ternas) cout<<terna[0]<<" "<<terna[1]<<" "<<terna[2]<<endl;
    }
    return 0;
}
