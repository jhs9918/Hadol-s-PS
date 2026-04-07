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
 * Problem: 단지번호붙이기
 * Platform: BOJ
 * Problem Number: 2667
 * URL: https://www.acmicpc.net/problem/2667
 * Category: Dfs
 * Difficulty: Silver I
 */


int arr[26][26];
bool visited[26][26];

int n;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cnt;


void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;
    for ( int i = 0 ; i < 4 ; i++ ) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
        if (!visited[tx][ty] && arr[tx][ty] == 1) {
            dfs(tx,ty);
        }
    }
}

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        for (int j = 0; j < n; j++) {
            arr[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && arr[i][j] == 1) {
                cnt=0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto& i : v) cout << i << "\n";
    return 0;
}
