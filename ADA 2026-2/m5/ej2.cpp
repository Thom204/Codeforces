#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    cout << fixed << setprecision(1);

    while (testCases--) {
        int N;
        cin >> N;

        vector<pair<double, double>> points(N);
        for (auto &[x, y] : points) cin >> x >> y;

        vector<double> minDistance(N, numeric_limits<double>::max());
        vector<bool> visited(N, false);
        minDistance[0] = 0.0;

        double totalLength = 0.0;

        for (int i = 0; i < N; ++i) {
            int u = -1;
            for (int j = 0; j < N; ++j) {
                if (!visited[j] && (u == -1 || minDistance[j] < minDistance[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            totalLength += minDistance[u];

            for (int v = 0; v < N; ++v) {
                if (visited[v]) continue;

                double dx = points[u].first - points[v].first;
                double dy = points[u].second - points[v].second;
                double edgeLength = hypot(dx, dy);
                minDistance[v] = min(minDistance[v], edgeLength);
            }
        }

        cout << totalLength << '\n';
    }

    return 0;
}
