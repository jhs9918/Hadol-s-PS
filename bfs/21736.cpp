#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
using namespace std;

/*
 * Problem: 헌내기는 친구가 필요해
 * Platform: BOJ
 * Problem Number: 21736
 * URL: https://www.acmicpc.net/problem/21736
 * Category: Bfs
 * Difficulty: Silver II
 */

int n, m;
char box[600][600];
bool visited[600][600];
pair<int, int> start;
int ans = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int> > q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  //맵 밖인지
            if (visited[nx][ny]) continue;   //방문 체크
            if (box[nx][ny] == 'X') continue;  //갈 수 있는 곳인지

            q.push({nx, ny});
            visited[nx][ny] = true;
            if (box[nx][ny] == 'P') ans++;
        }
    }
    if (ans == 0) cout << "TT";
    else cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0 ; i < n ; i++ ) {
        string line;
        cin >> line;
        for (int j = 0 ; j < m ; j++ ) {
            box[i][j] = line[j];
            if (line[j] == 'I') start = {i, j};
        }
    }
    bfs();

    return 0;
}
