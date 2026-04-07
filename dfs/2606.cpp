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
 * Problem: 바이러스
 * Platform: BOJ
 * Problem Number: 2606
 * URL: https://www.acmicpc.net/problem/2606
 * Category: Dfs
 * Difficulty: Silver III
 */

vector<int> graph[101];
bool visited[101];

int cnt = 0;
void dfs(int node) {
    visited[node] = true;
    for (auto& v : graph[node]) {
        if (!visited[v]) {
            dfs(v);
            cnt++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성
    int n, m;

    cin >> n;
    cin >> m;

    for (int i = 0 ; i < m ; i++) {
        int v, g;
        cin >> v >> g;
        graph[v].push_back(g);
        graph[g].push_back(v); //양방향 연결(방향 없음)
    }
    dfs(1);
    cout << cnt;
    return 0;
}
