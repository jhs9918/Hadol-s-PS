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
 * Problem: 단어 정렬
 * Platform: BOJ
 * Problem Number: 1181
 * URL: https://www.acmicpc.net/problem/1181
 * Category: Sorting
 * Difficulty: Silver V
 */

auto cmp = [](const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    set<string, decltype(cmp)> s(cmp);
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        s.insert(line);
    }
    for (auto& it : s) cout << it << '\n';

    return 0;
}
