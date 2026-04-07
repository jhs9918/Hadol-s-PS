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

using ll = long long;

/*
 * Problem: 랜선 자르기
 * Platform: BOJ
 * Problem Number: 1654
 * URL: https://www.acmicpc.net/problem/1654
 * Category: Binary_Search
 * Difficulty: Silver II
 */

vector<int> lan;

ll cut(int len) {
    ll max = 0;
    for (auto& l : lan) {
        max += l/len;
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성

    ll n;
    int k; cin >> k >> n;
    lan.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> lan[i];
    }
    ll lo = 1, hi = *max_element(lan.begin(), lan.end());
    while (lo < hi) {
        ll mid = (lo + hi+1) / 2;
        if (cut(mid)>=n) lo = mid;
        else hi = mid-1;
    }
    cout << lo;

    return 0;
}
