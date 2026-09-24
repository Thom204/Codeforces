#include <bits/stdc++.h>
#include <sstream>
#define c(d,v) d.find(v) != d.end()

using namespace std;

class Node{
public:
    bool visited;
    Node(bool c): visited(false){}
};

const int BOARD_SIZE = 8;

class graph{
public:
    bool adj[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE][BOARD_SIZE] = {false};

    vector<pair<int, int>> moves = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
    };

    void initializeAdjMatrix() {
        for (int x = 0; x < BOARD_SIZE; x++) {
            for (int y = 0; y < BOARD_SIZE; y++) {
                for (auto [dx, dy] : moves) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE) {
                        adj[x][y][nx][ny] = true;
                    }
                }
            }
        }
    }

    pair<int, int> chessToCoords(string pos) {
        return {pos[0] - 'A', pos[1] - '1'};
    }

    int minKnightMoves(string start, string end) {
        if (start == end) return 0;
        
        queue<pair<int, int>> q;
        bool visited[BOARD_SIZE][BOARD_SIZE] = {false};
        
        auto [sx, sy] = chessToCoords(start);
        auto [ex, ey] = chessToCoords(end);
        
        q.push({sx, sy});
        visited[sx][sy] = true;
        int moves_count = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x == ex && y == ey) return moves_count;
                
                for (int nx = 0; nx < BOARD_SIZE; nx++) {
                    for (int ny = 0; ny < BOARD_SIZE; ny++) {
                        if (adj[x][y][nx][ny] && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            moves_count++;
        }
        return -1; 
    }
};


int main() {
    graph board;
    board.initializeAdjMatrix();
    int C;
    cin >> C;
    
    while (C--) {
        string start, end;
        cin >> start >> end;
        cout << board.minKnightMoves(start, end) << endl;
    }
    
    return 0;
}
