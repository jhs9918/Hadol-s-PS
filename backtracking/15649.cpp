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
 * Problem: N과 M (1)
 * Platform: BOJ
 * Problem Number: 15649
 * URL: https://www.acmicpc.net/problem/15649
 * Category: Backtracking
 * Difficulty: Silver III
 */

int n, m;
vector<int> result;      // 현재까지 선택한 수열
bool used[9];            // 숫자 사용 여부 체크 (1~8까지만 사용)

// depth: 현재까지 선택한 개수
void backtrack(int depth) {
    // 기저 조건: M개를 모두 선택했으면 출력
    if (depth == m) {
        for (int x : result) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    // 1부터 N까지 시도
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;  // 이미 사용한 숫자는 스킵

        // 1. 선택
        used[i] = true;
        result.push_back(i);

        // 2. 탐색
        backtrack(depth + 1);

        // 3. 되돌리기
        result.pop_back();
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    backtrack(0);  // depth 0부터 시작

    return 0;
}
