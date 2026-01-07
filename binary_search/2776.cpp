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
 * Problem: 암기왕
 * Platform: BOJ
 * Problem Number: 2776
 * URL: https://www.acmicpc.net/problem/2776
 * Category: Binary_Search
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m,t;
    cin >> t;
    while (t--) {
        vector<int> s;
        cin >> n;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            s.push_back(num);
        }
        sort(s.begin(), s.end());

        cin >> m;
        for (int i = 0; i < m; i++) {
            int target;
            cin >> target;
            cout << binary_search(s.begin(), s.end(), target) << '\n';
        }
    }


    return 0;
}
