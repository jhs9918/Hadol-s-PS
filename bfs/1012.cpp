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
 * Problem: 유기농 배추
 * Platform: BOJ
 * Problem Number: 1012
 * URL: https://www.acmicpc.net/problem/1012
 * Category: Bfs
 * Difficulty: Silver II
 */




int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int box[50][50];
bool visited[50][50];

int x, y, k;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [xx, yy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            if (visited[nx][ny]) continue;
            if (box[nx][ny] != 1) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        int ans = 0;

        cin >> x >> y >> k;
        int a, b;
        for (int i = 0 ; i < k ; i++) {
            cin >> a >> b;
            box[a][b] = 1;
        }
        for ( int i = 0 ; i < x ; i++) {
            for ( int j = 0 ; j < y ; j++) {
                if (box[i][j] == 1 and not visited[i][j]) {
                    bfs(i, j);  //1을 만났을 때 방문한 곳이 아니면 bfs를 돌려 인접한 1을 모두 방문처리함
                    ans++;  //bfs를 돌린 횟수가 총 구역의 수
                }
            }
        }

        cout << ans << endl;

        memset(visited, false, sizeof(visited));
        memset(box, 0, sizeof(box));

    }




    return 0;
}
