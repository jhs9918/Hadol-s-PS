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
 * Problem: 다이얼
 * Platform: BOJ
 * Problem Number: 5622
 * URL: https://www.acmicpc.net/problem/5622
 * Category: String
 * Difficulty: Bronze II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dial[] = {
        3,3,3,        // ABC → 2번
        4,4,4,        // DEF → 3번
        5,5,5,        // GHI → 4번
        6,6,6,        // JKL → 5번
        7,7,7,        // MNO → 6번
        8,8,8,8,      // PQRS → 7번
        9,9,9,        // TUV → 8번
        10,10,10,10   // WXYZ → 9번
    };

    string line;
    cin >> line;
    int ans = 0;

    for (char c : line) ans += dial[c - 'A'];

    cout << ans;


    return 0;
}
