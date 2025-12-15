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
 * Problem: 문자열 판별
 * Platform: BOJ
 * Problem Number: 16500
 * URL: https://www.acmicpc.net/problem/16500
 * Category: String
 * Difficulty: Gold V
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    bool dp[101] = {false};
    dp[0] = true;

    for (int i = 1; i <= s.length(); i++) {
        for (const string& word : words) {
            int len = word.length();
            if (i >= len && dp[i - len]) {
                if (s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    cout << (dp[s.length()] ? 1 : 0) << '\n';

    return 0;
}
