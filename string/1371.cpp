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
 * Problem: 가장 많은 글자
 * Platform: BOJ
 * Problem Number: 1371
 * URL: https://www.acmicpc.net/problem/1371
 * Category: String
 * Difficulty: Bronze II
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v(26,0);
    string line;
    while (getline(cin, line)) {  // EOF까지 전체 읽기
        stringstream ss(line);
        string word;
        while (ss >> word) {
            for (auto c : word) {
                v[c - 'a']++;
            }
        }
    }
    int maxVal = *max_element(v.begin(), v.end());

    for (int i = 0; i < 26; i++) {
        if (v[i] == maxVal) {
            cout << (char)('a' + i) << " ";
        }
    }
    return 0;
}
