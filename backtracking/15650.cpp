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
 * Problem: N과 M (2)
 * Platform: BOJ
 * Problem Number: 15650
 * URL: https://www.acmicpc.net/problem/15650
 * Category: Backtracking
 * Difficulty: Silver III
 */

int n, m;
vector<int> result;
bool used[9];

void backtrack(int depth) {
    if (depth == m) {
        for (int x : result) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }


    for (int i = result.empty() ? 1 : result.back()+1 ; i <= n; i++) {
        if (used[i]) continue;

        used[i] = true;
        result.push_back(i);

        backtrack(depth + 1);

        result.pop_back();
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    backtrack(0);

    return 0;
}
