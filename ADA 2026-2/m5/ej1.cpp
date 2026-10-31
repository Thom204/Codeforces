#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int P;
    cin >> P;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, difficulty;
        cin >> u >> v >> difficulty;
        graph[u].push_back({v, difficulty});
        graph[v].push_back({u, difficulty});
    }

    vector<int> destinations(P);
    for (int &destination : destinations) cin >> destination;

    const long long INF = numeric_limits<long long>::max();
    vector<long long> distance(N + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pending;

    distance[0] = 0;
    pending.push({0, 0});

    while (!pending.empty()) {
        auto [currentDistance, u] = pending.top();
        pending.pop();

        if (currentDistance != distance[u]) continue;

        for (auto [v, difficulty] : graph[u]) {
            long long candidate = currentDistance + difficulty;
            if (candidate < distance[v]) {
                distance[v] = candidate;
                pending.push({candidate, v});
            }
        }
    }

    for (int destination : destinations) {
        if (distance[destination] == INF) cout << "ZOMBI\n";
        else cout << distance[destination] << '\n';
    }

    return 0;
}
