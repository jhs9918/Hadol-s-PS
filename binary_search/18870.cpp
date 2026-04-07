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
 * Problem: 좌표 압축
 * Platform: BOJ
 * Problem Number: 18870
 * URL: https://www.acmicpc.net/problem/18870
 * Category: Binary Search
 * Difficulty: Silver II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];  // push_back

    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()),sorted_v.end());

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(sorted_v.begin(),sorted_v.end(), v[i]) - sorted_v.begin();
        cout << idx << " ";  // idx가 압축된 값
    }
    return 0;
}
