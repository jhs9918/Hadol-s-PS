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
 * Problem: 촌수계산
 * Platform: BOJ
 * Problem Number: 2644
 * URL: https://www.acmicpc.net/problem/2644
 * Category: Dfs
 * Difficulty: Silver II
 */

vector<int> graph[101];
bool visited[101];
bool found = false;

int s, d;
void dfs(int node, int depth) {
    visited[node] = true;
    if (found) return;
    for (auto& i : graph[node]) {
        if (i==d) {
            found = true;
            cout << ++depth;
            return;
        }
        if (!visited[i]) {
            dfs(i, depth+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    cin >> s >> d;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(s, 0);
    if (!found) {
        cout << -1;
    }
    return 0;
}
