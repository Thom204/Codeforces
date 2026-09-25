#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>


using namespace std;

void combine(const vector<int>& c, const vector<int>& sumaRes, int idx, int t, int tobj, int& mejorSobrante) {
    if (t == tobj) {
        mejorSobrante = 0;
        return;
    }

    if (idx == static_cast<int>(c.size())) {
        mejorSobrante = min(mejorSobrante, tobj - t);
        return;
    }

    int maxsum = t + sumaRes[idx];
    if (maxsum <= tobj && tobj - maxsum >= mejorSobrante) {
        return;
    }

    //branch
    if (t + c[idx] <= tobj) {
        combine(c, sumaRes, idx + 1, t + c[idx], tobj, mejorSobrante);
    }

    combine(c, sumaRes, idx + 1, t, tobj, mejorSobrante);
}


int minTSobrante(vector<int> &c, int tobj) {
    sort(c.begin(), c.end(), greater<int>());

    vector<int> sumaRestante(c.size() + 1, 0);
    for (int i = c.size() - 1; i >= 0; --i) {
        sumaRestante[i] = sumaRestante[i + 1] + c[i];
    }

    int mejorSobrante = tobj;
    combine(c, sumaRestante, 0, 0, tobj, mejorSobrante);
    return mejorSobrante;
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int nc, n;
    string s;
    cin>>nc;

    for(;nc>0;nc--){
        getline(cin>>ws, s);
        stringstream ss(s);
        ss>>n;
        vector<int> canciones;
        int duracion;
        while (ss >> duracion) {
            canciones.push_back(duracion);
        }

        cout << minTSobrante(canciones, n) << '\n';
    }

    return 0;
}