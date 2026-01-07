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
 * Problem: 세수정렬
 * Platform: BOJ
 * Problem Number: 2752
 * URL: https://www.acmicpc.net/problem/2752
 * Category: Sorting
 * Difficulty: Bronze IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<int> s;
    for (int i = 0 ; i < 3 ; i++) {
        int n; cin >> n;
        s.insert(n);
    }
    for (auto &it : s) {
        cout << it << " ";
    }

    return 0;
}
