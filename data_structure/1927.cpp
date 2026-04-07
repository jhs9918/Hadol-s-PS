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
 * Problem: 최소 힙
 * Platform: BOJ
 * Problem Number: 1927
 * URL: https://www.acmicpc.net/problem/1927
 * Category: Data_Structure
 * Difficulty: Silver II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int n; cin >> n;
    while (n--) {
        long long x; cin >> x;
        if (x == 0 && pq.empty()) {
            cout << 0 << "\n";
        }
        else if (x == 0) {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}
