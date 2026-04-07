#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int r;
    cin >> r;
    int pcc, pcd, pdc, pdd;
    cin >> pcc >> pcd >> pdc >> pdd;

    // dp[0] = 상대가 C일 때 최대 점수
    // dp[1] = 상대가 D일 때 최대 점수
    vector<long long> dp(2, LLONG_MIN/2);
    dp[0] = 0; // 1라운드 상대는 무조건 C

    for (int i = 0; i < r; i++) {
        vector<long long> ndp(2, LLONG_MIN/2);
        // 상대가 C일 때
        if (dp[0] != LLONG_MIN/2) {
            ndp[0] = max(ndp[0], dp[0] + pcc); // 내가 C
            ndp[1] = max(ndp[1], dp[0] + pdc); // 내가 D
        }
        // 상대가 D일 때
        if (dp[1] != LLONG_MIN/2) {
            ndp[0] = max(ndp[0], dp[1] + pcd); // 내가 C
            ndp[1] = max(ndp[1], dp[1] + pdd); // 내가 D
        }
        dp = ndp;
    }

    cout << max(dp[0], dp[1]);
}