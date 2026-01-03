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
 * Problem: 제로
 * Platform: BOJ
 * Problem Number: 10773
 * URL: https://www.acmicpc.net/problem/10773
 * Category: Data_Structure
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 코드 작성

    stack<int> s;
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 0) s.pop();
        else s.push(t);
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum;


    return 0;
}
