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

int n;

bool visited[100][100];
char normal[100][100];
char blind[100][100];


/*
 * Problem: 적록색약
 * Platform: BOJ
 * Problem Number: 10026
 * URL: https://www.acmicpc.net/problem/10026
 * Category: Bfs
 * Difficulty: Gold V
 */

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(char box[][100], char color, int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while (!q.empty()) {
        auto [xx, yy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];


            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (box[nx][ny] != color) continue;

            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }
}

int countArea(char box[][100]) {
    int ans=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char color = box[i][j];
            if (!visited[i][j]) {
                bfs(box, color, i, j);
                ans++;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            normal[i][j] = line[j];
            if (normal[i][j] == 'R') blind[i][j] = 'G';
            else blind[i][j] = normal[i][j];
        }
    }
    cout << countArea(normal) << " " << countArea(blind);
    return 0;
}
