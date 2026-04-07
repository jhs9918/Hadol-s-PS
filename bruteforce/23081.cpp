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
 * Problem: 오델로
 * Platform: BOJ
 * Problem Number: 23081
 * URL: https://www.acmicpc.net/problem/23081
 * Category: Bruteforce
 * Difficulty: Silver II
 */

int n;
char arr[500][500];

int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

// (r, c)에 흑돌(B)을 놓았을 때 뒤집히는 백돌(W) 개수 반환
int countFlips(int r, int c) {
    if (arr[r][c] != '.') return -1; // 빈 칸이 아니면 놓을 수 없음

    int total = 0;
    for (int d = 0; d < 8; d++) {
        int nr = r + dx[d], nc = c + dy[d];
        int cnt = 0;

        // 상대방(W) 돌이 연속으로 나오는 동안 전진
        while (nr >= 0 && nr < n && nc >= 0 && nc < n && arr[nr][nc] == 'W') {
            nr += dx[d];
            nc += dy[d];
            cnt++;
        }

        // 연속된 W 뒤에 내 돌(B)이 있으면 유효한 방향
        if (cnt > 0 && nr >= 0 && nr < n && nc >= 0 && nc < n && arr[nr][nc] == 'B') {
            total += cnt;
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < n; j++) {
            arr[i][j] = line[j];
        }
    }

    int bestFlips = 0;
    int bestX = -1, bestY = -1;

    // arr[i][j] = 좌표
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int flips = countFlips(i, j);
            if (flips > bestFlips) {
                bestFlips = flips;
                bestX = j; // x = 열(column) 1-indexed
                bestY = i; // y = 행(row)    1-indexed
            }
        }
    }

    if (bestFlips == 0) {
        cout << "PASS\n";
    } else {
        cout << bestX << " " << bestY << "\n";
        cout << bestFlips << "\n";
    }

    return 0;
}
