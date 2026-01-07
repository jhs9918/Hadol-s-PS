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
 * Problem: 카드 정렬하기
 * Platform: BOJ
 * Problem Number: 1715
 * URL: https://www.acmicpc.net/problem/1715
 * Category: Data_Structure
 * Difficulty: Gold IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pq.push(a);
    }

    int sum = 0, a = 0, b = 0, tmp = 0;
    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        tmp = a + b;
        sum += tmp;
        pq.push(tmp);
    }
    cout << sum ;
    return 0;
}
