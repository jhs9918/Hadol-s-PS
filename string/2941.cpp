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
 * Problem: 크로아티아 알파벳
 * Platform: BOJ
 * Problem Number: 2941
 * URL: https://www.acmicpc.net/problem/2941
 * Category: String
 * Difficulty: Silver V
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string special[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    int cnt = 0;
    int i = 0;
    string s;
    cin >> s;

    while (i < s.size()) {
        bool found = false;
        for (auto& sp : special) {
            if (s.substr(i, sp.size()) == sp) {
                cnt++;
                i += sp.size();
                found = true;
                break;
            }
        }
        if (!found) {
            cnt++;
            i++;
        }
    }
    cout << cnt;
    return 0;
}
