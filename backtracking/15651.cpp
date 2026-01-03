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
 * Problem: N과 M (3)
 * Platform: BOJ
 * Problem Number: 15651
 * URL: https://www.acmicpc.net/problem/15651
 * Category: Backtracking
 * Difficulty: Silver III
 */
int n,m;
vector<int> result;
bool used[8];

void backtraking(int depth) {
    if (depth == m) {
        for (auto it = result.begin(); it != result.end(); it++) {
            cout << *it << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        used[i] = true;
        result.push_back(i);

        backtraking(depth + 1);

        used[i] = false;
        result.pop_back();
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
