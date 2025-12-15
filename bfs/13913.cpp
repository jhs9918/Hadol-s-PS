#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <type_traits>
using namespace std;

/*
 * Problem: 숨바꼭질 4
 * Platform: BOJ
 * Problem Number: 13913
 * URL: https://www.acmicpc.net/problem/13913
 * Category: Bfs
 * Difficulty: Gold IV
 */
//

#define IMAX 100001

int n, k;

int dist[IMAX];
int parent[IMAX];


void bfs() {
    queue<int> q;
    int p = n;  q.push(p);
    fill(dist, dist+IMAX , -1);
    dist[p] = 0;

    while (!q.empty()) {
        int x = q.front(); q.pop();

        if (x == k) break; //목표 도달 시 조기 종료

        int next[3] = { x-1 , x+1, 2*x};
        for (int i = 0; i < 3; i++) {
            int nx = next[i];

            if (nx < 0 || nx >= IMAX) continue; //범위 검사
            if (dist[nx] != -1 ) continue; //방문 검사

            q.push(nx);
            dist[nx] = dist[x] + 1;
            parent[nx] = x;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성
    cin >> n >> k;
    bfs();

    cout << dist[k] << endl;
    vector<int> path;

    int cur = k;
    while (cur != n) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(n);
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << ' ';
    }
    cout << '\n';

    return 0;
}
