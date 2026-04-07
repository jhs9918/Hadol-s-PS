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
 * Problem: 집합
 * Platform: BOJ
 * Problem Number: 11723
 * URL: https://www.acmicpc.net/problem/11723
 * Category: Implementation
 * Difficulty: Silver V
 */
//비트마스킹 기억하기!


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M;
    cin >> M;

    int S = 0;

    while (M--) {
        string op;
        int x = 0;
        cin >> op;

        if (op == "add") {
            cin >> x;
            S |= (1 << x);
        } else if (op == "remove") {
            cin >> x;
            S &= ~(1 << x);
        } else if (op == "check") {
            cin >> x;
            cout << ((S >> x) & 1) << '\n';
        } else if (op == "toggle") {
            cin >> x;
            S ^= (1 << x);
        } else if (op == "all") {
            S = (1 << 21) - 1;
        } else if (op == "empty") {
            S = 0;
        }
    }

    return 0;
}
