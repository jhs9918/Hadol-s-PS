#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

/*
 * Problem: 이모티콘
 * Platform: BOJ
 * Problem Number: 14226
 * URL: https://www.acmicpc.net/problem/14226
 * Category: Bfs
 * Difficulty: Gold IV
 */

int n;
int dist[1001][1001];  // dist[screen][clipboard]

int bfs() {
    queue<pair<int, int>> q;  // {screen, clipboard}
    memset(dist, -1, sizeof(dist));

    // 시작: 화면 1개, 클립보드 0개
    q.push({1, 0});
    dist[1][0] = 0;

    while (!q.empty()) {
        auto [s, c] = q.front(); q.pop();

        // 목표 도달
        if (s == n) return dist[s][c];

        // 1. 복사: (s, c) -> (s, s)
        if (dist[s][s] == -1) {
            dist[s][s] = dist[s][c] + 1;
            q.push({s, s});
        }

        // 2. 붙여넣기: (s, c) -> (s+c, c)
        if (c > 0 && s + c <= 1000 && dist[s+c][c] == -1) {
            dist[s+c][c] = dist[s][c] + 1;
            q.push({s+c, c});
        }

        // 3. 삭제: (s, c) -> (s-1, c)
        if (s > 0 && dist[s-1][c] == -1) {
            dist[s-1][c] = dist[s][c] + 1;
            q.push({s-1, c});
        }
    }

    return -1;  // 도달 불가능
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cout << bfs() << '\n';

    return 0;
}
