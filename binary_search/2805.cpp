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
 * Problem: 나무 자르기
 * Platform: BOJ
 * Problem Number: 2805
 * URL: https://www.acmicpc.net/problem/2805
 * Category: Binary_Search
 * Difficulty: Silver II
 */

vector<int> tree;

ll cut(int H) {
    ll sum = 0;
    for (auto& t : tree) {
        if (t>H) sum += t - H;
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; cin >> n >> m;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    int lo = 0, hi = *max_element(tree.begin(), tree.end());
    int mid;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (cut(mid)>=m) lo = mid;
        else hi = mid-1;
    }
    cout << lo;

    return 0;
}