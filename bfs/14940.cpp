#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <tuple>
using namespace std;

/*
 * Problem: 쉬운 최단거리
 * Platform: BOJ
 * Problem Number: 14940
 * URL: https://www.acmicpc.net/problem/14940
 * Category: Bfs
 * Difficulty: Silver I
 */

int n, m;
int box[1000][1000];
int dist[1000][1000];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> target;

void bfs() {
    queue<pair<int, int>> q;   //목표지점 2부터 bfs 검사를 통해 확인
    q.push(target);
    dist[target.first][target.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //n,m 배열 밖인지 검사

            if (dist[nx][ny]!=-1) continue;   //이미 방문

            if (box[nx][ny] == 0) continue;   //갈 수 없는 곳

            dist[nx][ny] = dist[x][y] + 1; // 거리 업데이트
            q.push({nx, ny});
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> k;
            if (k==2)  target = {i, j}; // 목표지점
            box[i][j] = k;
            dist[i][j] = -1;
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}