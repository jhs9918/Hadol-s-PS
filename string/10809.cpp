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
 * Problem: 알파벳 찾기
 * Platform: BOJ
 * Problem Number: 10809
 * URL: https://www.acmicpc.net/problem/10809
 * Category: String
 * Difficulty: Bronze II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string line;
    vector<int> v(26, -1);
    cin >> line;
    int i = 0;
    for (auto c : line) {
        int idx = c - 'a';
        if (v[idx] == -1) v[idx] = i;
        i++;
    }

    for (auto i : v) cout << i << ' ';

    return 0;
}
