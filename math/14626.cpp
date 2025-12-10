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
 * Problem: ISBN
 * Platform: BOJ
 * Problem Number: 14626
 * URL: https://www.acmicpc.net/problem/14626
 * Category: Math
 * Difficulty: Bronze I
 */

int main() {
    string s;
    cin >> s;

    // 0~9를 넣어보면서 확인, 브루트 포스로 해결함
    for (int x = 0; x <= 9; x++) {
        int sum = 0;
        for (int i = 0; i < 13; i++) {
            int digit = (s[i] == '*') ? x : s[i] - '0';
            sum += digit * ((i % 2 == 0) ? 1 : 3);
        }
        if (sum % 10 == 0) {
            cout << x;
            return 0;
        }
    }
}
