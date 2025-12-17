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
 * Problem: 듣보잡
 * Platform: BOJ
 * Problem Number: 1764
 * URL: https://www.acmicpc.net/problem/1764
 * Category: Simulation
 * Difficulty: Silver IV
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m; cin>>n>>m;

    set<string> heard;
    set<string> result;

    string name;
    while (n--) {
        cin>>name;
        heard.insert(name);
    }

    while (m--) {
        cin >> name;
        if (heard.count(name)) {
            result.insert(name);
        }
    }

    cout << result.size() << '\n';
    for (const auto &name : result) {
        cout << name << '\n';
    }

    return 0;
}
