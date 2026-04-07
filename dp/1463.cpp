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
 * Problem: 1로 만들기
 * Platform: BOJ
 * Problem Number: 1463
 * URL: https://www.acmicpc.net/problem/1463
 * Category: Dp
 * Difficulty: Silver III
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int dp[1000001];

    dp[1] = 0;
    int n; cin>>n;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1]+1;
        if (i%2 == 0 ) dp[i] = min(dp[i],dp[i/2]+1);
        if (i%3 == 0 ) dp[i] = min(dp[i],dp[i/3]+1);
    }
    cout<<dp[n];

    return 0;
}
