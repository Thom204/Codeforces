#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    explicit DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

struct Road {
    int cityA;
    int cityB;
    int cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int N, M, airportCost;
        cin >> N >> M >> airportCost;

        vector<Road> roads(M);
        for (Road &road : roads) {
            cin >> road.cityA >> road.cityB >> road.cost;
            --road.cityA;
            --road.cityB;
        }

        sort(roads.begin(), roads.end(), [](const Road &a, const Road &b) {
            return a.cost < b.cost;
        });

        DSU dsu(N);
        long long totalCost = 0;
        int airports = N;

        for (const Road &road : roads) {
            if (road.cost >= airportCost) break;

            if (dsu.unite(road.cityA, road.cityB)) {
                totalCost += road.cost;
                --airports;
            }
        }

        totalCost += 1LL * airports * airportCost;
        cout << totalCost << ' ' << airports << '\n';
    }

    return 0;
}
