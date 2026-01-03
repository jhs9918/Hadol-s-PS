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
 * Problem: 최대 힙
 * Platform: BOJ
 * Problem Number: 11279
 * URL: https://www.acmicpc.net/problem/11279
 * Category: Data_Structure
 * Difficulty: Silver II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int> pq;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        if (m == 0 && pq.empty()) {
            cout << 0 << '\n';
        }
        else if (m == 0) {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else {
            pq.push(m);
        }
    }
    return 0;
}