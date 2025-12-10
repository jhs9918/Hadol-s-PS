#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
using namespace std;

/*
 * Problem: 케빈 베이컨의 6단계 법칙
 * Platform: BOJ
 * Problem Number: 1389
 * URL: https://www.acmicpc.net/problem/1389
 * Category: Bfs
 * Difficulty: Silver I
 */

int n, m;

vector<int> adj[101];


int bfs(int idx) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(idx);
    dist[idx] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dist[i];
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    int a, b;
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); //양방향
    }

    int min = INT_MAX;
    int idx = 0;
    for (int i = 1 ; i <= n ; i++) {
        int now = bfs(i);
        if (now < min) {
            min = now;
            idx = i;
        }
    }
    cout << idx;

    return 0;
}