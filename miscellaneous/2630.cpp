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
 * Problem: 색종이 만들기
 * Platform: BOJ
 * Problem Number: 2630
 * URL: https://www.acmicpc.net/problem/2630
 * Category: Miscellaneous
 * Difficulty: Silver II
 */

vector<vector<int>> maps;
int white = 0, blue = 0;

void cut(int row, int col, int size) {
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (maps[i][j] != maps[row][col]) {
                int half = size / 2;
                cut(row,      col,      half);
                cut(row,      col+half, half);
                cut(row+half, col,      half);
                cut(row+half, col+half, half);
                return;
            }
        }
    }
    if (maps[row][col] == 0) white++;
    else blue++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성
    int n; cin >> n;
    maps.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
        }
    }
    cut(0, 0, n);
    cout << white << "\n" << blue;


    return 0;
}
