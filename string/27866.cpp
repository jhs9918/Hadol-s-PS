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
 * Problem: 문자와 문자열
 * Platform: BOJ
 * Problem Number: 27866
 * URL: https://www.acmicpc.net/problem/27866
 * Category: String
 * Difficulty: Bronze V
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // string line;
    // cin >> line;
    // int n; cin >> n;
    // cout << line[n-1];

    vector<int> v = {0, 1, 2};
    int tmp = 0, answer = 0;
    int len = v.size();
    for(int i = 0 ; i<len ; i++) {
        cout << v.front() << "--";
        tmp = v[i];
        cout<<tmp<<"--";
        answer+=tmp;
    }

}
