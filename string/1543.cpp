#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <istream>
using namespace std;

/*
 * Problem: 문서 검색
 * Platform: BOJ
 * Problem Number: 1543
 * URL: https://www.acmicpc.net/problem/1543
 * Category: String
 * Difficulty: Silver V
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string line;
    string c;
    string p;
    getline(cin, line);
    getline(cin, c);
    int size_l = line.length();
    int size_c = c.size();
    int ans = 0;
    while (size_l >= size_c) {
        p = line.substr(0,size_c);
        if (c==p) {
            ans++;
            line.erase(0, size_c);
            size_l -= size_c;
        }
        else {
            line.erase(begin(line));
            size_l -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}