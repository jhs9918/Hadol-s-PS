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
 * Problem: 1로 만들기
 * Platform: BOJ
 * Problem Number: 1463
 * URL: https://www.acmicpc.net/problem/1463
 * Category: BFS
 * Difficulty: Silver III
 */

int x;

int dist[1000001];

int bfs() {
    if (x == 1) return 0;
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int dx[3] = {cur*3, cur*2, cur+1};
        for ( int i = 0 ; i < 3 ; i++) {
            int nx = dx[i];
            if (nx > 1000000 || nx > x || dist[nx]!=-1) continue;
            dist[nx] = dist[cur]+1;
            if (nx == x) return dist[nx];
            q.push(nx);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dist, -1, sizeof(dist));
    cin >> x;
    cout << bfs();
    return 0;
}
