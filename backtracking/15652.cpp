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
 * Problem: N과 M (4)
 * Platform: BOJ
 * Problem Number: 15652
 * URL: https://www.acmicpc.net/problem/15652
 * Category: Backtracking
 * Difficulty: Silver III
 */

int n,m;
vector<int> result;
bool used[9];


void backtraking(int depth) {
    if (depth == m) {
        for (auto &w : result) {
            cout << w << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = result.empty() ? 1 : result.back() ; i <= n ; i++) {
        used[i] = true;
        result.push_back(i);

        backtraking(depth + 1);

        result.pop_back();
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    backtraking(0);


    return 0;
}
