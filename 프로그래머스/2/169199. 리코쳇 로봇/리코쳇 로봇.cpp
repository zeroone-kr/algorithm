#include <bits/stdc++.h>
using namespace std;

struct point {
    int row;   
    int col;
    int dist;
};

typedef struct point POINT;


int solution(vector<string> board) {
    int H = board.size();        // 행 개수
    int W = board[0].size();     // 열 개수
    pair<int,int> start, goal;

    
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (board[r][c] == 'R') start = { r, c };
            else if (board[r][c] == 'G') goal  = { r, c };
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<POINT> q;
    q.push({ start.first, start.second, 0 });
    visited[start.first][start.second] = true;

    // 4 directions
    const int dr[4] = { -1,  1,  0,  0 };  // row 변화량
    const int dc[4] = {  0,  0, -1,  1 };  // col 변화량

    while (!q.empty()) {
        POINT p = q.front(); q.pop();
        int r    = p.row;
        int c    = p.col;
        int dist = p.dist;

        if (r == goal.first && c == goal.second) {
            return dist;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r, nc = c;

            // 벽 또는 'D'에 부딪힐 때까지 이동
            while (true) {
                int tr = nr + dr[dir];
                int tc = nc + dc[dir];
                if (tr < 0 || tr >= H || tc < 0 || tc >= W) break;
                if (board[tr][tc] == 'D') break;
                nr = tr;
                nc = tc;
            }

            // 한 칸도 못 움직였으면 다음 방향
            if (nr == r && nc == c) 
                continue;

            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({ nr, nc, dist + 1 });
            }
        }
    }

    return -1;
}
