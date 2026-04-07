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
 * Problem: 구간 합 구하기 4
 * Platform: BOJ
 * Problem Number: 11659
 * URL: https://www.acmicpc.net/problem/11659
 * Category: DP
 * Difficulty: Silver III
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    long long dp[100000];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        long long num; cin >> num;
        dp[i] = dp[i-1] + num;
    }
    while (m--) {
        int a, b; cin >> a >> b;
        cout << dp[b] - dp[a-1] << "\n";
    }

    return 0;
}
