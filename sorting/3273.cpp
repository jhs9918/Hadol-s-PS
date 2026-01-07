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
 * Problem: 두 수의 합
 * Platform: BOJ
 * Problem Number: 3273
 * URL: https://www.acmicpc.net/problem/3273
 * Category: Sorting
 * Difficulty: Silver III
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
    }
    int x; cin >> x;

    sort(arr.begin(), arr.end());

    int ans = 0;
    int left = 0, right = n-1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x) {
            ans++;
            left++;
            right--;
        } else if (sum > x) {
            right--;
        } else {
            left++;
        }
    }
    cout << ans << '\n';
    return 0;
}
