#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    while (testCases--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> cost(N, vector<int>(M));
        for (auto &row : cost) {
            for (int &cell : row) cin >> cell;
        }

        const long long INF = numeric_limits<long long>::max();
        vector<vector<long long>> distance(N, vector<long long>(M, INF));
        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> pending;

        distance[0][0] = 0;
        pending.push({0, 0, 0});

        while (!pending.empty()) {
            auto [currentCost, r, c] = pending.top();
            pending.pop();

            if (currentCost != distance[r][c]) continue;
            if (r == N - 1 && c == M - 1) break;

            for (int direction = 0; direction < 4; ++direction) {
                int nr = r + dr[direction];
                int nc = c + dc[direction];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

                long long nextCost = currentCost + cost[nr][nc];
                if (nextCost < distance[nr][nc]) {
                    distance[nr][nc] = nextCost;
                    pending.push({nextCost, nr, nc});
                }
            }
        }

        cout << distance[N - 1][M - 1] << '\n';
    }

    return 0;
}
