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
 * Problem: 2×n 타일링
 * Platform: BOJ
 * Problem Number: 11726
 * URL: https://www.acmicpc.net/problem/11726
 * Category: Dp
 * Difficulty: Silver III
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= 1000; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    int n; cin >> n;
    cout << dp[n];
    return 0;
}
