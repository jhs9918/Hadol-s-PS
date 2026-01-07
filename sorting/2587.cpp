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
 * Problem: 대표값2
 * Platform: BOJ
 * Problem Number: 2587
 * URL: https://www.acmicpc.net/problem/2587
 * Category: Sorting
 * Difficulty: Bronze II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr;
    int mean=0;

    for (int i = 0 ; i<5 ; i++) {
        int n; cin >> n;
        arr.push_back(n);
        mean+=n;
    }
    sort(arr.begin(), arr.end());

    cout << int(mean/5);
    cout << arr[2] << '\n';

    return 0;
}
