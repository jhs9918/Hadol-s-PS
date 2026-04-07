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
 * Problem: 연결 요소의 개수
 * Platform: BOJ
 * Problem Number: 11724
 * URL: https://www.acmicpc.net/problem/11724
 * Category: Dfs
 * Difficulty: Silver II
 */



bool visited[1001];
vector<int> graph[1001];


void dfs(int node) {
    visited[node] = true;

    for  (auto& next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; cin>>n>>m;

    for (int i = 0 ; i < m ; i++) {
        int v, g;
        cin >> v >> g;
        graph[v].push_back(g);
        graph[g].push_back(v);
    }

    int count = 0;

    for ( int i = 1 ; i <= n ; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count;
    return 0;
}
