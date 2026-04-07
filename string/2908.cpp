#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;

/*
 * Problem: 상수
 * Platform: BOJ
 * Problem Number: 2908
 * URL: https://www.acmicpc.net/problem/2908
 * Category: String
 * Difficulty: Bronze II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());  // 먼저 뒤집고
    reverse(b.begin(), b.end());

    int na = stoi(a);
    int nb = stoi(b);

    cout << (na > nb ? na : nb);

    return 0;
}