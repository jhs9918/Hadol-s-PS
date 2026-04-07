#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <array>
using namespace std;

/*
 * Problem: 계단 오르기
 * Platform: BOJ
 * Problem Number: 2579
 * URL: https://www.acmicpc.net/problem/2579
 * Category: Miscellaneous
 * Difficulty: Silver III
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long  n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) { cout << v[0]; return 0; }
    vector<array<long long,2>> dp(n+1, {0,0});
    dp[0][0] = 0;
    dp[1][1] = v[0];
    dp[2][0] = v[1];
    dp[2][1] = v[0]+v[1];
    for (int i = 3; i <= n; i++) {

        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + v[i-1]; //2칸 전의 값 중 큰값 -> 스택 0
        dp[i][1] = dp[i-1][0]+v[i-1]; //1칸 전의 값 -> 스택 1됨
    }
    cout << max(dp[n][0], dp[n][1]);

    return 0;
}
