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
 * Problem: 회문
 * Platform: BOJ
 * Problem Number: 17609
 * URL: https://www.acmicpc.net/problem/17609
 * Category: String
 * Difficulty: Gold V
 */

//투포인터로 체크
bool isPal(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r]) { l++; r--; }

        if (l >= r) {
            cout << 0 << "\n";  // 팰린드롬
        } else if (isPal(s, l+1, r) || isPal(s, l, r-1)) {
            cout << 1 << "\n";  // 유사 팰린드롬
        } else {
            cout << 2 << "\n";  // 일반 문자열
        }
    }

    return 0;
}


