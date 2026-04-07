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
 * Problem: 1, 2, 3 더하기
 * Platform: BOJ
 * Problem Number: 9095
 * URL: https://www.acmicpc.net/problem/9095
 * Category: Dp
 * Difficulty: Silver III
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dp[11];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        cout << dp[x] << endl;
    }
    return 0;
}
