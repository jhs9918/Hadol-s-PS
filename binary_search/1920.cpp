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
 * Problem: 수 찾기
 * Platform: BOJ
 * Problem Number: 1920
 * URL: https://www.acmicpc.net/problem/1920
 * Category: Binary_Search
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int m; cin >> m;
    while (m--) {
        int target; cin >> target;
        cout << binary_search(arr.begin(), arr.end(), target) << '\n';
    }

    return 0;
}
